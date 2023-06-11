#include "Logger.h"

int main() {
    Logger::Initialize("log.txt");
    Logger::EnableTimestamps(true);

    Logger::Log(LogLevel::Info, "Program started");
    Logger::Log(LogLevel::Debug, "Debug message");
    Logger::Log(LogLevel::Error, "Error occurred");

    return 0;
}