#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "Brain.hpp"
#include <string>

class Human
{
private:
	const Brain m_Brain;
public:
	Human();
	std::string identify();
	const Brain &getBrain();
	~Human();
};


#endif