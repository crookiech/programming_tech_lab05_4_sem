#include "TagGame.h"
#include <iostream>

void TagGame::Shuffle() {
    CreateLogger* consoleLoggerFactory = new CreateConsoleLogger();
    CreateLogger* fileLoggerFactory = new CreateFileLogger();

    ILogger* newConsoleLoggerFactory = consoleLoggerFactory->FactoryMethod();
    newConsoleLoggerFactory->Log("Calling TagGame::Shuffle...");
    ILogger* newFileLoggerFactory = fileLoggerFactory->FactoryMethod();
    newFileLoggerFactory->Log("Calling TagGame::Shuffle...");

    std::cout << "The field is mixed up" << std::endl;

    newConsoleLoggerFactory->Log("TagGame::Shuffle successfully called.");
    newFileLoggerFactory->Log("TagGame::Shuffle successfully called.");

    delete consoleLoggerFactory;
    delete newConsoleLoggerFactory;
    delete fileLoggerFactory;
    delete newFileLoggerFactory;
}
void TagGame::Move(int index, int step) { // step - шаг (1 - вверх, 2 - вниз, 3 - влево, 4 - вправо)
    CreateLogger* consoleLoggerFactory = new CreateConsoleLogger();
    CreateLogger* fileLoggerFactory = new CreateFileLogger();

    ILogger* newConsoleLoggerFactory = consoleLoggerFactory->FactoryMethod();
    newConsoleLoggerFactory->Log("Calling TagGame::Move...");
    ILogger* newFileLoggerFactory = fileLoggerFactory->FactoryMethod();
    newFileLoggerFactory->Log("Calling TagGame::Move...");

    if (index < 1 || index > 15) {
        std::cout << "You entered the chip index incorrectly" << std::endl;
    } else {
        if (step == 1) {
            std::cout << index << " moved up" << std::endl;
        } else if (step == 2) {
            std::cout << index << " moved down" << std::endl;
        } else if (step == 3) {
            std::cout << index << " moved left" << std::endl;
        } else if (step == 4) {
            std::cout << index << " moved right" << std::endl;
        } else {
            std::cout << "Such a step cannot be taken" << std::endl;
        }
    }
    newConsoleLoggerFactory->Log("TagGame::Move successfully called.");
    newFileLoggerFactory->Log("TagGame::Move successfully called.");

    delete consoleLoggerFactory;
    delete newConsoleLoggerFactory;
    delete fileLoggerFactory;
    delete newFileLoggerFactory;
}
void TagGame::Play() {}
void TagGame::Info() {}

RateYourMindPal::RateYourMindPal() {
    CreateLogger* consoleLoggerFactory = new CreateConsoleLogger();
    CreateLogger* fileLoggerFactory = new CreateFileLogger();

    ILogger* newConsoleLoggerFactory = consoleLoggerFactory->FactoryMethod();
    newConsoleLoggerFactory->Log("Calling RateYourMindPal::RateYourMindPal...");
    ILogger* newFileLoggerFactory = fileLoggerFactory->FactoryMethod();
    newFileLoggerFactory->Log("Calling RateYourMindPal::RateYourMindPal...");

    std::cout << "You created " << gameName << std::endl;

    newConsoleLoggerFactory->Log("RateYourMindPal::RateYourMindPal successfully called.");
    newFileLoggerFactory->Log("RateYourMindPal::RateYourMindPal successfully called.");

    delete consoleLoggerFactory;
    delete newConsoleLoggerFactory;
    delete fileLoggerFactory;
    delete newFileLoggerFactory;
}
void RateYourMindPal::Play() {
    CreateLogger* consoleLoggerFactory = new CreateConsoleLogger();
    CreateLogger* fileLoggerFactory = new CreateFileLogger();

    ILogger* newConsoleLoggerFactory = consoleLoggerFactory->FactoryMethod();
    newConsoleLoggerFactory->Log("Calling RateYourMindPal::Play...");
    ILogger* newFileLoggerFactory = fileLoggerFactory->FactoryMethod();
    newFileLoggerFactory->Log("Calling RateYourMindPal::Play...");

    std::cout << "You're playing " << gameName << std::endl;

    newConsoleLoggerFactory->Log("RateYourMindPal::Play successfully called.");
    newFileLoggerFactory->Log("RateYourMindPal::Play successfully called.");

    delete consoleLoggerFactory;
    delete newConsoleLoggerFactory;
    delete fileLoggerFactory;
    delete newFileLoggerFactory;
}
void RateYourMindPal::Info() {
    CreateLogger* consoleLoggerFactory = new CreateConsoleLogger();
    CreateLogger* fileLoggerFactory = new CreateFileLogger();

    ILogger* newConsoleLoggerFactory = consoleLoggerFactory->FactoryMethod();
    newConsoleLoggerFactory->Log("Calling RateYourMindPal::Info...");
    ILogger* newFileLoggerFactory = fileLoggerFactory->FactoryMethod();
    newFileLoggerFactory->Log("Calling RateYourMindPal::Info...");

    std::cout << "You're playing " << gameName << std::endl;

    newConsoleLoggerFactory->Log("RateYourMindPal::Info successfully called.");
    newFileLoggerFactory->Log("RateYourMindPal::Info successfully called.");

    delete consoleLoggerFactory;
    delete newConsoleLoggerFactory;
    delete fileLoggerFactory;
    delete newFileLoggerFactory;
}

ClassicTagGame::ClassicTagGame() {
    CreateLogger* consoleLoggerFactory = new CreateConsoleLogger();
    CreateLogger* fileLoggerFactory = new CreateFileLogger();

    ILogger* newConsoleLoggerFactory = consoleLoggerFactory->FactoryMethod();
    newConsoleLoggerFactory->Log("Calling RateYourMindPal::ClassicTagGame...");
    ILogger* newFileLoggerFactory = fileLoggerFactory->FactoryMethod();
    newFileLoggerFactory->Log("Calling RateYourMindPal::ClassicTagGame...");

    std::cout << "You created " << gameName << std::endl;

    newConsoleLoggerFactory->Log("RateYourMindPal::ClassicTagGame successfully called.");
    newFileLoggerFactory->Log("RateYourMindPal::ClassicTagGame successfully called.");

    delete consoleLoggerFactory;
    delete newConsoleLoggerFactory;
    delete fileLoggerFactory;
    delete newFileLoggerFactory;
}
void ClassicTagGame::Play() {
    CreateLogger* consoleLoggerFactory = new CreateConsoleLogger();
    CreateLogger* fileLoggerFactory = new CreateFileLogger();

    ILogger* newConsoleLoggerFactory = consoleLoggerFactory->FactoryMethod();
    newConsoleLoggerFactory->Log("Calling ClassicTagGame::Play...");
    ILogger* newFileLoggerFactory = fileLoggerFactory->FactoryMethod();
    newFileLoggerFactory->Log("Calling ClassicTagGame::Play...");

    std::cout << "You're playing " << gameName << std::endl;

    newConsoleLoggerFactory->Log("ClassicTagGame::Play successfully called.");
    newFileLoggerFactory->Log("ClassicTagGame::Play successfully called.");

    delete consoleLoggerFactory;
    delete newConsoleLoggerFactory;
    delete fileLoggerFactory;
    delete newFileLoggerFactory;
}
void ClassicTagGame::Info() {
    CreateLogger* consoleLoggerFactory = new CreateConsoleLogger();
    CreateLogger* fileLoggerFactory = new CreateFileLogger();

    ILogger* newConsoleLoggerFactory = consoleLoggerFactory->FactoryMethod();
    newConsoleLoggerFactory->Log("Calling ClassicTagGame::Info...");
    ILogger* newFileLoggerFactory = fileLoggerFactory->FactoryMethod();
    newFileLoggerFactory->Log("Calling ClassicTagGame::Info...");

    std::cout << "You're playing " << gameName << std::endl;

    newConsoleLoggerFactory->Log("ClassicTagGame::Info successfully called.");
    newFileLoggerFactory->Log("ClassicTagGame::Info successfully called.");

    delete consoleLoggerFactory;
    delete newConsoleLoggerFactory;
    delete fileLoggerFactory;
    delete newFileLoggerFactory;
}
