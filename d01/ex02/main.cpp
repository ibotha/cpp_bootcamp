#include "ZombieEvent.hpp"
#include <iostream>
#include <ctime>

int main() {
	std::srand(std::time(0));
	ZombieEvent ZE = ZombieEvent();

	ZE.setType(ARMLESS);
	for (int i = 0; i < 3; i++) {
		ZE.randomChump();
	}

	ZE.setType(HUMANINDISGUISE);
	for (int i = 0; i < 3; i++) {
		ZE.randomChump();
	}

	ZE.setType(LEGLESS);
	Zombie *z = ZE.newZombie("Greg");
	z->announce();
	delete z;
	return 0;
}