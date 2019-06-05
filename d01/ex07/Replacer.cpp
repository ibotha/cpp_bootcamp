#include "Replacer.hpp"
#include <iostream>

Replacer::Replacer(std::string filename, std::string s1, std::string s2)
    :m_Input(filename), m_Output(filename + ".replace"), m_S1(s1), m_S2(s2), is_Ready(false)
{
    if (m_Input && m_Output)
        is_Ready = true;
}

void Replacer::flush()
{
    int cut = m_Buffer.length();
    for (int i = m_S1.length() - 1; i >= 0; i--)
    {
        int k = i;
        int j;
        for (j = m_Buffer.length() - 1; j >= 0 && k >= 0; j--)
        {
            std::cout << i << " " << m_S1[i] << " " << j << " " << m_Buffer[j] << " " << k << "\n";
            if (m_S1[k] == m_Buffer[j])
                k--;
            else
                break;
        }
        cut = cut < k ? cut : k;
    }
    std::cout << std::endl << m_Buffer << std::endl << cut << std::endl;
}

bool Replacer::ready() const { return is_Ready; }

void Replacer::run()
{
    while(!m_Input.eof())
    {
        char buffer[64];
        m_Input.read(buffer, 64);
        m_Buffer += buffer;
        flush();
    }
}

Replacer::~Replacer()
{
    m_Input.close();
    m_Output.close();
}