#include "ZombieHorde.hpp"
#include <string>


ZombieHorde::ZombieHorde(int n)
	:m_Size(n)
{
	m_Zombies = new Zombie[m_Size];
}

void ZombieHorde::Announce() {
	for (int i = 0; i < m_Size; i++) {
		m_Zombies[i].announce();
	}
}

ZombieHorde::~ZombieHorde()
{
	delete[] m_Zombies;
}