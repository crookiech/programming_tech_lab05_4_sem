#ifndef ILOGGER_H
#define ILOGGER_H

#include <string>

class ILogger {
public:
    virtual void Log(const std::string& message);
    virtual ~ILogger() {};
};

class ConsoleLogger : public ILogger {
public:
    void Log(const std::string& message) override;
};

class FileLogger : public ILogger {
private:
    std::string filename = "C:/programming_tech/test/log.txt";
public:
    void Log(const std::string& message) override;
};

#endif
