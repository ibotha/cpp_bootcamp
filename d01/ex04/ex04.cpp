#include <string>
#include <iostream>

void print_pointer(std::string *htib) {
	std::cout << *htib << "\n";
}

void print_ref(std::string &htib) {
	std::cout << htib << "\n";
}

int main() {
	std::string htib = "HI THIS IS BRAIN";
	print_pointer(&htib);
	print_ref(htib);
	return 0;
}