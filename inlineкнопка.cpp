#include <tgbot/tgbot.h>

int main() {
    TgBot::Bot bot("ВАШ_ТОКЕН");

    bot.getEvents().onCommand("start", [&bot](auto msg) {
        auto kb = std::make_shared<TgBot::InlineKeyboardMarkup>();
        TgBot::InlineKeyboardButton::Ptr btn(new TgBot::InlineKeyboardButton);
        btn->text = "Нажми!";
        btn->callbackData = "click";
        kb->inlineKeyboard.push_back({ btn });

        bot.getApi().sendMessage(msg->chat->id, "Привет!", false, 0, kb);
        });

    bot.getEvents().onCallbackQuery([&bot](auto q) {
        bot.getApi().answerCallbackQuery(q->id, "Ты нажал!");
        });

    TgBot::TgLongPoll poll(bot);
    while (true) poll.start();
}