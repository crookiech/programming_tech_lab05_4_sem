#include "CreateLogger.h"
#include "ILogger.h"

ILogger* CreateConsoleLogger::FactoryMethod() {
    return new ConsoleLogger();
}

ILogger* CreateFileLogger::FactoryMethod() {
    return new FileLogger();
}