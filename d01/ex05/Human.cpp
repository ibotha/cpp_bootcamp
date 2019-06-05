#include "Human.hpp"
#include <iostream>

Human::Human()
{
}

std::string Human::identify()
{
	return m_Brain.identify();
}

const Brain &Human::getBrain()
{
	return m_Brain;
}

Human::~Human()
{
}