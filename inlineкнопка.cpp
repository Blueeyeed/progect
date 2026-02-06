#include <tgbot/tgbot.h>

int main() {
    TgBot::Bot bot("ТОКЕН");

    bot.getEvents().onCommand("start", [&bot](auto msg) {
        auto kb = std::make_shared<TgBot::InlineKeyboardMarkup>();
        TgBot::InlineKeyboardButton::Ptr btn(new TgBot::InlineKeyboardButton);
        btn->text = "Привет!";
        btn->callbackData = "Нажми";
        kb->inlineKeyboard.push_back({ btn });

        bot.getApi().sendMessage(msg->chat->id, "!", false, 0, kb);
        });

    bot.getEvents().onCallbackQuery([&bot](auto q) {
        bot.getApi().answerCallbackQuery(q->id, "Òû íàæàë!");
        });

    TgBot::TgLongPoll poll(bot);
    while (true) poll.start();
}
