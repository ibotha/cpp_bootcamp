#include "ZombieEvent.hpp"
#include <random>

std::string zombieNames[10] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};

ZombieEvent::ZombieEvent()
	:m_Type(ARMLESS)
{
}

void ZombieEvent::setType(ZombieType t)
{
	m_Type = t;
}

Zombie* ZombieEvent::newZombie(std::string name)
{
	return new Zombie(name, m_Type);
}

void ZombieEvent::randomChump()
{
	Zombie z = Zombie(zombieNames[std::rand() % 10], m_Type);
	z.announce();
}

ZombieEvent::~ZombieEvent() {}