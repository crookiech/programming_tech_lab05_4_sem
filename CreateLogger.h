#ifndef CREATELOGGER_H
#define CREATELOGGER_H

#include "ILogger.h"

class CreateLogger {
public:
    virtual ILogger* FactoryMethod() = 0; 
    virtual ~CreateLogger() {};
};

class CreateConsoleLogger : public CreateLogger {
public:
    ILogger* FactoryMethod() override;
};

class CreateFileLogger : public CreateLogger {
private:
    std::string filename;
public:
    ILogger* FactoryMethod() override;
};

#endif