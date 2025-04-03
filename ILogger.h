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
    std::string filename = ":/log.txt";
public:
    int CountLinesInFile(const std::string& filename);
    void ClearFile(const std::string& filename);
    void Log(const std::string& message) override;
};

#endif
