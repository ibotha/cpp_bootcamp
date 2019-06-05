#include "Zombie.hpp"
#include "random"
#include <iostream>

std::string zombieNames[10] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};

std::string Zombie::s_TypeString[4] = {"Armless", "Human in diguise", "Brainless", "Legless"};

Zombie::Zombie()
{
	m_Name = zombieNames[rand() % 10];
	m_Type = static_cast<ZombieType>(rand() % 4);
}

Zombie::Zombie(std::string name, ZombieType t)
	:m_Name(name), m_Type(t)
{
}

void Zombie::announce()
{
	std::cout << "(" << m_Name << " <" << s_TypeString[m_Type] << ">) BRRRRAAAAAIIIINNNSSSS!!!!!\n";
}

Zombie::~Zombie()
{
}