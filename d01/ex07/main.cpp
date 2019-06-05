#include <string>
#include <iostream>
#include "Replacer.hpp"

int main(int ac, char **av)
{
    if (ac < 4)
    {
        std::cout << "usage: ./replace [filename] [s1] [s2] \n";
        return 0;
    }

    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    if (s1.length() == 0 || s2.length() == 0 || filename.length() == 0)
    {
        std::cout << "Arguments must not be empty\n";
        return 0;
    }

    Replacer r(filename, s1, s2);

    if (!r.ready())
    {
        std::cout << "File error\n";
        return 0;
    }

    r.run();

    return 0;
}