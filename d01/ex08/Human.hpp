#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <string>

class Human
{
private:
    enum AttackType {
        MELEE = 0,
        RANGED = 1,
        SHOUT = 2
    };
    static const std::string attackTypes[];

    AttackType convert(std::string type);
    void meleeAttack(std::string const & target);
    void rangedAttack(std::string const & target);
    void intimidatingShout(std::string const & target);
public:
    void action(std::string const & action_name, std::string const & target);
};

#endif