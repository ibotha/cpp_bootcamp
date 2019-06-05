#include "Pony.hpp"
#include <iostream>

Pony::Pony(std::string name)
    :m_Name(name)
{
    std::cout << m_Name << " the pony now exists!\n";
}

void Pony::BeUsefull()
{
    std::cout << m_Name << " the pony cannot be useful, since he is a pony\n";
}

Pony::~Pony()
{
    std::cout << m_Name << " the pony is gone!\n";
}