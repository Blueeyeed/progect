#include <iostream>
#include <string>
#include <thread>
#include "httplib.h"

const std::string BOT_TOKEN = "ВАШ_ТОКЕН_БОТА";
std::string chat_id = ""; // будет установлен при первом сообщении

// Отправка сообщения в Telegram
bool send_telegram_message(const std::string& text) {
    if (chat_id.empty()) return false;

    httplib::Client client("https://api.telegram.org");
    auto res = client.Post(
        ("/bot" + BOT_TOKEN + "/sendMessage").c_str(),
        R"({"chat_id":")" + chat_id + R"(","text":")" + text + R"("})",
        "application/json"
    );
    return res && res->status == 200;
}

int main() {
    // === Веб-сервер (сайт) ===
    httplib::Server svr;

    svr.Post("/send-to-telegram", [&](const httplib::Request& req, httplib::Response& res) {
        if (chat_id.empty()) {
            res.set_content(R"({"error":"Сначала напишите боту"})", "application/json");
            res.status = 400;
            return;
        }

        std::string message = req.body; // или распарсить JSON, если нужно
        if (send_telegram_message(message)) {
            res.set_content(R"({"ok":true})", "application/json");
        } else {
            res.set_content(R"({"error":"Ошибка отправки"})", "application/json");
            res.status = 500;
        }
    });

    // Запуск веб-сервера в фоне
    std::thread server_thread([&]() {
        std::cout << "Сервер запущен на http://localhost:8080\n";
        svr.listen("localhost", 8080);
    });

    // === Простой цикл для получения обновлений от Telegram (polling) ===
    std::cout << "Бот запущен. Напишите ему /start.\n";
    httplib::Client tg_client("https://api.telegram.org");

    long offset = 0;
    while (true) {
        std::string url = "/bot" + BOT_TOKEN + "/getUpdates?offset=" + std::to_string(offset);
        auto res = tg_client.Get(url.c_str());
        if (!res || res->status != 200) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            continue;
        }

        // Очень простой парсинг JSON (в реальном проекте используйте nlohmann/json)
        std::string body = res->body;
        size_t pos = body.find("\"text\":\"/start\"");
        if (pos != std::string::npos) {
            size_t id_pos = body.find("\"id\":");
            if (id_pos != std::string::npos) {
                size_t start = body.find(':', id_pos) + 1;
                size_t end = body.find(',', start);
                if (end == std::string::npos) end = body.find('}', start);
                chat_id = body.substr(start, end - start);
                // Удаляем лишние пробелы
                chat_id.erase(0, chat_id.find_first_not_of(" \t"));
                chat_id.erase(chat_id.find_last_not_of(" \t") + 1);
                std::cout << "Получен chat_id: " << chat_id << "\n";
            }
        }

        // Обновляем offset
        pos = body.find("\"update_id\":");
        if (pos != std::string::npos) {
            size_t start = body.find(':', pos) + 1;
            size_t end = body.find(',', start);
            if (end == std::string::npos) end = body.find('}', start);
            long upd_id = std::stol(body.substr(start, end - start));
            offset = upd_id + 1;
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    server_thread.join();
    return 0;
}