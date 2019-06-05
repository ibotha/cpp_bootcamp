#ifndef ZOMBIEHORDE
#define ZOMBIEHORDE
#include "Zombie.hpp"

class ZombieHorde
{
private:
	Zombie *m_Zombies;
	int m_Size;
public:
	ZombieHorde(int n);
	void Announce();
	~ZombieHorde();
};

#endif