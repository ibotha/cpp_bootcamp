#include "Human.hpp"
#include <iostream>

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

typedef void	(Human::*f)(const std::string &);

void Human::action(std::string const & action_name, std::string const & target)
{
	struct pair {
		std::string match;
		f func;
	};
	pair	attacks[3];

	attacks[0].match = "melee";
	attacks[0].func = &Human::meleeAttack;
	attacks[1].match = "ranged";
	attacks[1].func = &Human::rangedAttack;
	attacks[2].match = "shout";
	attacks[2].func = &Human::intimidatingShout;
    for (size_t i = 0; i < 3; i++)
    {
        if (action_name == attacks[i].match) {
			f function = attacks[i].func;
			(this->*function)(target);
			return;
		}
    }
	meleeAttack(target);
}