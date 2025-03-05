#include "CreateTagGame.h"
#include "C:/programming_tech/lab04/log/ILogger.h"
#include "C:/programming_tech/lab04/log/CreateLogger.h"
#include <iostream>

void CreateTagGame::info() {
    std::cout << "CreateTagGame - class for creating various types of tag games" << std::endl;
}

TagGame* CreateRateYourMindPal::FactoryMethod() {
    CreateLogger* consoleLoggerFactory = new CreateConsoleLogger();
    CreateLogger* fileLoggerFactory = new CreateFileLogger();

    ILogger* newConsoleLoggerFactory = consoleLoggerFactory->FactoryMethod();
    newConsoleLoggerFactory->Log("Calling CreateRateYourMindPal::FactoryMethod...");
    ILogger* newFileLoggerFactory = fileLoggerFactory->FactoryMethod();
    newFileLoggerFactory->Log("Calling CreateRateYourMindPal::FactoryMethod...");

    RateYourMindPal* mindPal = new RateYourMindPal();

    newConsoleLoggerFactory->Log("CreateRateYourMindPal::FactoryMethod successfully called.");
    newFileLoggerFactory->Log("CreateRateYourMindPal::FactoryMethod successfully called.");

    delete consoleLoggerFactory;
    delete newConsoleLoggerFactory;
    delete fileLoggerFactory;
    delete newFileLoggerFactory;

    return mindPal;
}
void CreateRateYourMindPal::info() {
    CreateLogger* consoleLoggerFactory = new CreateConsoleLogger();
    CreateLogger* fileLoggerFactory = new CreateFileLogger();

    ILogger* newConsoleLoggerFactory = consoleLoggerFactory->FactoryMethod();
    newConsoleLoggerFactory->Log("Calling CreateRateYourMindPal::info...");
    ILogger* newFileLoggerFactory = fileLoggerFactory->FactoryMethod();
    newFileLoggerFactory->Log("Calling CreateRateYourMindPal::info...");

    std::cout << "CreateRateYourMindPal - class for creating games \"Rate your mind pal\"" << std::endl;

    newConsoleLoggerFactory->Log("CreateRateYourMindPal::info successfully called.");
    newFileLoggerFactory->Log("CreateRateYourMindPal::info successfully called.");

    delete consoleLoggerFactory;
    delete newConsoleLoggerFactory;
    delete fileLoggerFactory;
    delete newFileLoggerFactory;
}

TagGame* CreateClassicTagGame::FactoryMethod() {
    CreateLogger* consoleLoggerFactory = new CreateConsoleLogger();
    CreateLogger* fileLoggerFactory = new CreateFileLogger();

    ILogger* newConsoleLoggerFactory = consoleLoggerFactory->FactoryMethod();
    newConsoleLoggerFactory->Log("Calling CreateClassicTagGame::FactoryMethod...");
    ILogger* newFileLoggerFactory = fileLoggerFactory->FactoryMethod();
    newFileLoggerFactory->Log("Calling CreateClassicTagGame::FactoryMethod...");

    ClassicTagGame* classicGame = new ClassicTagGame();

    newConsoleLoggerFactory->Log("CreateClassicTagGame::FactoryMethod successfully called.");
    newFileLoggerFactory->Log("CreateClassicTagGame::FactoryMethod successfully called.");

    delete consoleLoggerFactory;
    delete newConsoleLoggerFactory;
    delete fileLoggerFactory;
    delete newFileLoggerFactory;

    return classicGame;
}
void CreateClassicTagGame::info() {
    CreateLogger* consoleLoggerFactory = new CreateConsoleLogger();
    CreateLogger* fileLoggerFactory = new CreateFileLogger();

    ILogger* newConsoleLoggerFactory = consoleLoggerFactory->FactoryMethod();
    newConsoleLoggerFactory->Log("Calling CreateClassicTagGame::info...");
    ILogger* newFileLoggerFactory = fileLoggerFactory->FactoryMethod();
    newFileLoggerFactory->Log("Calling CreateClassicTagGame::info...");

    std::cout << "CreateClassicTagGame - class for creating classic tag games" << std::endl;

    newConsoleLoggerFactory->Log("CreateClassicTagGame::info successfully called.");
    newFileLoggerFactory->Log("CreateClassicTagGame::info successfully called.");

    delete consoleLoggerFactory;
    delete newConsoleLoggerFactory;
    delete fileLoggerFactory;
    delete newFileLoggerFactory;
}
