#include "ILogger.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>

std::string GetTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::localtime(&now_c);
    std::stringstream ss;
    ss << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

void ILogger::Log(const std::string& message) {}

void ConsoleLogger::Log(const std::string& message) {
    std::cout << "[Console][" << GetTimestamp() << "] " << message << std::endl;
}

void FileLogger::Log(const std::string& message) {
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << "[File][" << GetTimestamp() << "] " << message << std::endl;
        file.close();
    } else {
        std::cerr << "Error opening file: " << filename << std::endl;
    }
}
