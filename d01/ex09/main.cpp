#include "Logger.hpp"

int main()
{
    Logger l("out");
    l.log("console", "console stuff");
    l.log("file", "File stuff");
}