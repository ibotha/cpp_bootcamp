#include <fstream>
#include <iostream>
#include <sys/stat.h>

void printstream(std::istream &is)
{
    std::string line;
    while (std::getline(is, line))
    {
        if(!is.eof())
            std::cout << line << std::endl;
        else
            std::cout << line;
    }
}

int main(int ac, char** av)
{
    if (ac == 1) {
        printstream(std::cin);
    } else {
        for (int i = 1; i < ac; i++)
        {
            struct stat s;
            if( stat(av[i],&s) == 0 )
            {
                if( s.st_mode & S_IFDIR )
                {
                    std::cout << "cat: " << av[i] << ": Is a directory\n";
                }
                else if( s.st_mode & S_IFREG )
                {
                    std::ifstream is(av[i]);
                    if (is)
                    {
                        printstream(is);
                    }
                    else
                        std::cout << "cat: " << av[i] << ": Permission denied\n";
                }
                else
                {
                    std::cout << "cat: " << av[i] << ": No such file or directory\n";
                }
            }
            else
                std::cout << "cat: " << av[i] << ": No such file or directory\n";
        }
    }
}