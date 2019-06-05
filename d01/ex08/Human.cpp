#include "Human.hpp"
#include <iostream>

const std::string Human::attackTypes[] = {"melee", "ranged", "shout"};

Human::AttackType Human::convert(std::string type)
{
    for (size_t i = 0; i < (sizeof(attackTypes) / sizeof(std::string)); i++)
    {
        if (type == attackTypes[i]) return static_cast<AttackType>(i);
    }
    return MELEE;
}

void Human::meleeAttack(std::string const & target)
{
    std::cout << target << " just got meleed\n";
}

void Human::rangedAttack(std::string const & target)
{
    std::cout << target << " just got shot at\n";
}

void Human::intimidatingShout(std::string const & target)
{
    std::cout << target << " just got scolded\n";
}

void Human::action(std::string const & action_name, std::string const & target)
{
    switch (convert(action_name))
    {
    case MELEE:
        meleeAttack(target);
        break;
    case RANGED:
        rangedAttack(target);
        break;
    case SHOUT:
        intimidatingShout(target);
        break;
    default:
        break;
    }
}