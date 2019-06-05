#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <fstream>

class Logger
{
private:
    enum Destination {
        CONSOLE = 0,
        FILE = 1,
        SHOUT = 2
    };
    static const std::string s_Destinations[];

    Destination convert(std::string const type);
    void logToFile(std::string const message);
    void logToConsole(std::string const message);
    std::string makeLogEntry(std::string const message);
    std::ofstream m_LogFile;
public:
    Logger(std::string const filename);
    void log(const std::string destination, const std::string message);
};

#endif