#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon)
    :m_Name(name), m_Weapon(weapon)
{
}

void HumanA::attack()
{
    std::cout << m_Name << " attacks with " << m_Weapon.getType() << "\n";
}

HumanA::~HumanA()
{
}
