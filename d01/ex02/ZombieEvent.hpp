#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP
#include "Zombie.hpp"

class ZombieEvent {

public:
	ZombieEvent();

	void setType(ZombieType t);

	Zombie* newZombie(std::string name);

	void randomChump();

	~ZombieEvent();

private:

	ZombieType m_Type;

};

#endif