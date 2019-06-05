#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB
{
private:
    std::string m_Name;
    Weapon *m_Weapon;
public:
    HumanB(std::string name);
    void setWeapon(Weapon &weapon);
    void attack();
    ~HumanB();
};

#endif