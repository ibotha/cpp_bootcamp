#include "Logger.hpp"
#include <iostream>
#include <ctime>

const std::string Logger::s_Destinations[] = {"console", "file"};

Logger::Destination Logger::convert(std::string const type)
{
    for (size_t i = 0; i < (sizeof(s_Destinations) / sizeof(std::string)); i++)
    {
        if (type == s_Destinations[i]) return static_cast<Destination>(i);
    }
    return CONSOLE;
}

Logger::Logger(std::string const filename)
    :m_LogFile(filename)
{
}

void Logger::logToFile(std::string const log)
{
    m_LogFile << log << "\n";
}

void Logger::logToConsole(std::string const log)
{
    std::cout << log << "\n";
}

std::string Logger::makeLogEntry(const std::string message)
{
    std::string ret;
    time_t now = std::time(0);
    ret = std::ctime(&now);
    ret = ret.substr(0, ret.length() - 1);
    ret += ": " + message;
    return ret;
}

void Logger::log(std::string const destination, std::string const message)
{
    switch(convert(destination))
    {
        case CONSOLE:
            logToConsole(makeLogEntry(message));
            break;
        case FILE:
            logToFile(makeLogEntry(message));
            break;
        default:
            break;
    }
}