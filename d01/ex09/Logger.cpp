#include "Logger.hpp"
#include <iostream>
#include <ctime>

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

typedef void	(Logger::*f)(std::string);

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
	struct pair {
		std::string match;
		f func;
	};
	pair	dests[2];

	dests[0].match = "console";
	dests[0].func = &Logger::logToConsole;
	dests[1].match = "file";
	dests[1].func = &Logger::logToFile;
    for (size_t i = 0; i < 2; i++)
    {
        if (destination == dests[i].match) {
			f function = dests[i].func;
			(this->*function)(message);
			return;
		}
    }
	logToConsole(message);
}