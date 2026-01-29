//8432405566:AAFSOtgvKorPLTsFvCYxifBdP8GGI7xq6RA @myolympik_bot
//8492826423:AAFgg1jDS7dTlnPKhsWogxm62GK92U8u87E - 2 бот @Olimpic_Kazan_bot

#include <iostream>
#include <string>
#include <stdio.h>
#include <tgbot/tgbot.h>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <wtypes.h>

using namespace std;
using namespace TgBot;

int main() {

    Bot bot("8432405566:AAFSOtgvKorPLTsFvCYxifBdP8GGI7xq6RA");

    const string documentMimeType = "application/pdf";
    string documentFilePath;

    bool is7_8ClassSelected = false;

    bot.getEvents().onCommand("start", [&bot](Message::Ptr message) {

        ReplyKeyboardMarkup::Ptr keyboard(new ReplyKeyboardMarkup);

        vector<KeyboardButton::Ptr> row3;
        KeyboardButton::Ptr startButton6(new KeyboardButton);
        startButton6->text = "👨‍🏫 7-8 классы";
        row3.push_back(startButton6);

        KeyboardButton::Ptr startButton7(new KeyboardButton);
        startButton7->text = "👨‍🎓 9-11 классы";
        row3.push_back(startButton7);

        keyboard->keyboard.push_back(row3);
        keyboard->resizeKeyboard = true;
        keyboard->oneTimeKeyboard = false;
        keyboard->selective = false; //konpki

        bot.getApi().sendMessage(message->chat->id,
            "Привет!✋ Я - твой бот-помощник для подготовки к олимпиаде по программированию 🖥.\n👨‍🏫 Выберите класс:",
            0, 0, keyboard);
        });//privetstvie

    bot.getEvents().onAnyMessage([&bot](Message::Ptr message) {

        string text = message->text;


        if (text.empty() || text[0] == '/') {
            return;
        }

        if (text == "👨‍🏫 7-8 классы") {
            bot.getApi().sendMessage(message->chat->id, "Вы перешли на олимпиаду для 7-8 классов 👨‍🏫 !");

            ReplyKeyboardMarkup::Ptr keyboard(new ReplyKeyboardMarkup);

            vector<KeyboardButton::Ptr> row0;
            KeyboardButton::Ptr startButton1(new KeyboardButton);
            startButton1->text = "1 вариант 👨‍💻";
            row0.push_back(startButton1);

            KeyboardButton::Ptr startButton2(new KeyboardButton);
            startButton2->text = "2 вариант 👨‍💻";
            row0.push_back(startButton2);

            vector<KeyboardButton::Ptr> row1;
            KeyboardButton::Ptr startButton3(new KeyboardButton);
            startButton3->text = "3 вариант 👨‍💻";
            row1.push_back(startButton3);

            KeyboardButton::Ptr startButton4(new KeyboardButton);
            startButton4->text = "4 вариант 👨‍💻";
            row1.push_back(startButton4);

            vector<KeyboardButton::Ptr> row2;
            KeyboardButton::Ptr startButton5(new KeyboardButton);
            startButton5->text = "5 вариант 👨‍💻";
            row2.push_back(startButton5);

            KeyboardButton::Ptr startButton11(new KeyboardButton);
            startButton11->text = "🔙 Назад";
            row2.push_back(startButton11);

            keyboard->keyboard.push_back(row0);
            keyboard->keyboard.push_back(row1);
            keyboard->keyboard.push_back(row2);

            keyboard->resizeKeyboard = true;
            keyboard->oneTimeKeyboard = false;
            keyboard->selective = false;// knopki 

            bot.getApi().sendMessage(message->chat->id,
                "Выберите вариант:",
                0, 0, keyboard);

        }

        else if (text == "👨‍🎓 9-11 классы") {

            bot.getApi().sendMessage(message->chat->id, "Вы перешли на олимпиаду для 9-11 классов 👨‍🎓 !");

            ReplyKeyboardMarkup::Ptr keyboard(new ReplyKeyboardMarkup);

            vector<KeyboardButton::Ptr> row0;
            KeyboardButton::Ptr startButton10(new KeyboardButton);
            startButton10->text = "👨‍💻 Вариант 1";
            row0.push_back(startButton10);

            KeyboardButton::Ptr startButton20(new KeyboardButton);
            startButton20->text = "👨‍💻 Вариант 2";
            row0.push_back(startButton20);

            vector<KeyboardButton::Ptr> row1;
            KeyboardButton::Ptr startButton30(new KeyboardButton);
            startButton30->text = "👨‍💻 Вариант 3";
            row1.push_back(startButton30);

            KeyboardButton::Ptr startButton40(new KeyboardButton);
            startButton40->text = "👨‍💻 Вариант 4";
            row1.push_back(startButton40);

            vector<KeyboardButton::Ptr> row2;
            KeyboardButton::Ptr startButton50(new KeyboardButton);
            startButton50->text = "👨‍💻 Вариант 5";
            row2.push_back(startButton50);

            KeyboardButton::Ptr startButton11(new KeyboardButton);
            startButton11->text = "🔙 Назад";
            row2.push_back(startButton11);//knopki dlya 9-11 klaasov

            keyboard->keyboard.push_back(row0);
            keyboard->keyboard.push_back(row1);
            keyboard->keyboard.push_back(row2);

            keyboard->resizeKeyboard = true;
            keyboard->oneTimeKeyboard = false;
            keyboard->selective = false;

            bot.getApi().sendMessage(message->chat->id,
                "Выберите вариант:",
                0, 0, keyboard);
        }
        else if (text == "1 вариант 👨‍💻") {
            bot.getApi().sendMessage(message->chat->id, "⌨️ Сейчас предложу Вам вариант номер 1!");
            string documentFilePath = "content/Olymp_1.pdf";
            const string documentMimeType = "application/pdf";
            bot.getApi().sendDocument(message->chat->id, InputFile::fromFile(documentFilePath, documentMimeType));
        }
        else if (text == "2 вариант 👨‍💻") {
            bot.getApi().sendMessage(message->chat->id, "⌨️ Сейчас предложу Вам вариант номер 2!");
            string documentFilePath = "content/Olymp_2.pdf";
            const string documentMimeType = "application/pdf";
            bot.getApi().sendDocument(message->chat->id, InputFile::fromFile(documentFilePath, documentMimeType));
        }
        else if (text == "3 вариант 👨‍💻") {
            bot.getApi().sendMessage(message->chat->id, "⌨️ Сейчас предложу Вам вариант номер 3!");
            string documentFilePath = "content/Olymp_3.pdf";
            const string documentMimeType = "application/pdf";
            bot.getApi().sendDocument(message->chat->id, InputFile::fromFile(documentFilePath, documentMimeType));
        }
        else if (text == "4 вариант 👨‍💻") {
            bot.getApi().sendMessage(message->chat->id, "⌨️ Сейчас предложу Вам вариант номер 4!");
            string documentFilePath = "content/Olymp_4.pdf";
            const string documentMimeType = "application/pdf";
            bot.getApi().sendDocument(message->chat->id, InputFile::fromFile(documentFilePath, documentMimeType));
        }
        else if (text == "5 вариант 👨‍💻") {
            bot.getApi().sendMessage(message->chat->id, "⌨️ Сейчас предложу Вам вариант номер 5!");
            string documentFilePath = "content/Olymp_5.pdf";
            const string documentMimeType = "application/pdf";
            bot.getApi().sendDocument(message->chat->id, InputFile::fromFile(documentFilePath, documentMimeType));
        }
        else if (text == "👨‍💻 Вариант 1") {
            bot.getApi().sendMessage(message->chat->id, "⌨️ Сейчас предложу Вам вариант номер 1!");
            string documentFilePath = "content/9-11_Olymp1.pdf";
            const string documentMimeType = "application/pdf";
            bot.getApi().sendDocument(message->chat->id, InputFile::fromFile(documentFilePath, documentMimeType));
        }
        else if (text == "👨‍💻 Вариант 2") {
            bot.getApi().sendMessage(message->chat->id, "⌨️ Сейчас предложу Вам вариант номер 2!");
            string documentFilePath = "content/9-11_Olymp2.pdf";
            const string documentMimeType = "application/pdf";
            bot.getApi().sendDocument(message->chat->id, InputFile::fromFile(documentFilePath, documentMimeType));
        }
        else if (text == "👨‍💻 Вариант 3") {
            bot.getApi().sendMessage(message->chat->id, "⌨️ ейчас предложу Вам вариант номер 3!");
            string documentFilePath = "content/9-11_Olymp3.pdf";
            const string documentMimeType = "application/pdf";
            bot.getApi().sendDocument(message->chat->id, InputFile::fromFile(documentFilePath, documentMimeType));
        }
        else if (text == "👨‍💻 Вариант 4") {
            bot.getApi().sendMessage(message->chat->id, "⌨️ Сейчас предложу Вам вариант номер 4!");
            string documentFilePath = "content/9-11_Olymp4.pdf";
            const string documentMimeType = "application/pdf";
            bot.getApi().sendDocument(message->chat->id, InputFile::fromFile(documentFilePath, documentMimeType));
        }
        else if (text == "👨‍💻 Вариант 5") {
            bot.getApi().sendMessage(message->chat->id, "⌨️ Сейчас предложу Вам вариант номер 5!");
            string documentFilePath = "content/9-11_Olymp5.pdf";
            const string documentMimeType = "application/pdf";
            bot.getApi().sendDocument(message->chat->id, InputFile::fromFile(documentFilePath, documentMimeType));
        }
        else if (text == "🔙 Назад") {// выдача файлов

            ReplyKeyboardMarkup::Ptr keyboard(new ReplyKeyboardMarkup);

            vector<KeyboardButton::Ptr> row3;
            KeyboardButton::Ptr startButton12(new KeyboardButton);
            startButton12->text = "👨‍🏫 7-8 классы";
            row3.push_back(startButton12);

            KeyboardButton::Ptr startButton13(new KeyboardButton);
            startButton13->text = "👨‍🎓 9-11 классы";
            row3.push_back(startButton13);

            keyboard->keyboard.push_back(row3);
            keyboard->resizeKeyboard = true;
            keyboard->oneTimeKeyboard = false;
            keyboard->selective = false;//первые кнопки

            bot.getApi().sendMessage(message->chat->id, "Выберите класс:", 0, 0, keyboard);

        }

        else if (!text.empty()) {
            bot.getApi().sendMessage(message->chat->id, "❗️Пожалуйста, введите команду из меню.");
        }
        });

    try {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());

        TgLongPoll longPoll(bot);

        while (true) {
            printf("Long poll started\n");
            longPoll.start();
        }
    }
    catch (TgException& e) {
        printf("error: %s\n", e.what());
    }
    return 0;
}


