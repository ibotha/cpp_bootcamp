#include "Brain.hpp"
#include <sstream>

Brain::Brain()
{
}

std::string Brain::identify() const
{
	std::stringstream ss;
	ss << this;
	return ss.str();
}

Brain::~Brain()
{
}