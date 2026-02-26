#include <tgbot/tgbot.h>

int main() {
    Bot bot("8640784948:AAHV_APhp38Q4w0belQk3nmlvwxYIY98STQ");

    bot.getEvents().onCommand("start", [&bot](auto msg) {
        auto kb = make_shared<InlineKeyboardMarkup>();
        InlineKeyboardButton::Ptr btn(new InlineKeyboardButton);
        btn->text = "Привет!";
        btn->callbackData = "Нажми";
        kb->inlineKeyboard.push_back({ btn });

        bot.getApi().sendMessage(msg->chat->id, "!", false, 0, kb);
        };
    bot.getEvents().onCallbackQuery([&bot](auto q) {
        bot.getApi().answerCallbackQuery(q->id, "окак");
        };

    TgLongPoll poll(bot);
    while (true) poll.start();
}
