#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
    :m_Name(name), m_Weapon(nullptr)
{
}

void HumanB::attack()
{
    std::cout << m_Name << " attacks with " << m_Weapon->getType() << "\n";
}

void HumanB::setWeapon(Weapon &weapon)
{
    m_Weapon = &weapon;
}

HumanB::~HumanB()
{
}
