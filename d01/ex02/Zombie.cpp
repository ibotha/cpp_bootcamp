#include "Zombie.hpp"

#include <iostream>

std::string Zombie::s_TypeString[4] = {"Armless", "Human in diguise", "Brainless", "Legless"};

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