#ifndef REPLACER_HPP
#define REPLACER_HPP

#include <string>
#include <fstream>

class Replacer
{
private:

    std::ifstream m_Input;
    std::ofstream m_Output;
    std::string m_S1;
    std::string m_S2;
    std::string m_Buffer;

    bool is_Ready;
    void flush();

public:
    Replacer(std::string filename, std::string s1, std::string s2);

    bool ready() const;

    void run();

    ~Replacer();
};

#endif