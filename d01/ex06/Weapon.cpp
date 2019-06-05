#include "Weapon.hpp"

Weapon::Weapon(std::string type)
    :m_Type(type)
{
}

void Weapon::setType(std::string type)
{
    m_Type = type;
}

const std::string &Weapon::getType() const
{
    return m_Type;
}

Weapon::~Weapon()
{
}
