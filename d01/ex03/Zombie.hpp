#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <string>

enum ZombieType {
	ARMLESS = 0,
	HUMANINDISGUISE = 1,
	BRAINLESS = 2,
	LEGLESS = 3
};

class Zombie {

public:

	Zombie();
	Zombie(std::string name, ZombieType t);

	void announce();

	~Zombie();

private:
	std::string m_Name;
	ZombieType m_Type;
	static std::string s_TypeString[4];
};

#endif