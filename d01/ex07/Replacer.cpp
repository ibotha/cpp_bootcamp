#include "Replacer.hpp"
#include <iostream>

Replacer::Replacer(std::string filename, std::string s1, std::string s2)
    :m_Input(filename), m_Output(), m_S1(s1), m_S2(s2), is_Ready(false)
{
    if (m_Input)
    {
        m_Output.open(filename + ".replace");
        if (m_Output)
            is_Ready = true;
    }
}

unsigned int Replacer::findCut()
{
    int cut = m_Buffer.length() - 1;
    for (int i = m_S1.length() - 1; i >= 0; i--)
    {
        int k = i;
        int j;
        for (j = m_Buffer.length() - 1; j >= 0 && k >= 0; j--)
        {
            if (m_S1[k] == m_Buffer[j])
                k--;
            else
                break;
        }
        cut = cut < j ? cut : j;
    }
    return (unsigned int)cut;
}

std::string Replacer::replace(const std::string &src)
{
    size_t cursor = 0;
    std::string ret = "";
    while (true)
    {
        size_t found;
        found = src.find(m_S1, cursor);
        if (found == std::string::npos)
            break;
        ret += src.substr(cursor, found - cursor) + m_S2;
        cursor = found + m_S1.length();
    }
    ret += src.substr(cursor);
    return ret;
}

void Replacer::flush()
{
    std::string clearout;
    int cut = findCut();
    clearout = m_Buffer.substr(0, cut + 1);
    m_Buffer = m_Buffer.substr(cut + 1, m_Buffer.length());
    m_Output << replace(clearout);
}

bool Replacer::ready() const { return is_Ready; }

void Replacer::run()
{
    while(!m_Input.eof())
    {
        std::string read;
        getline(m_Input, read);
        m_Buffer += read + "\n";
        flush();
    }
}

Replacer::~Replacer()
{
    m_Input.close();
    m_Output.close();
}