#include "ZombieHorde.hpp"
#include <iostream>
#include <random>
#include <ctime>

int main() {
	std::srand(std::time(0));
	ZombieHorde ZH(3);
	ZH.Announce();
	return 0;
}