#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA
{
private:
    std::string m_Name;
    Weapon &m_Weapon;
public:
    HumanA(std::string name, Weapon &weapon);
    void attack();
    ~HumanA();
};

#endif