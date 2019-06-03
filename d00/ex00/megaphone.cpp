#include <iostream>
#include <string>

int main(int argc, char** argv) {
    if (argc > 1) {
        std::string ret;

        for (int i = 1; i < argc; i++) {
            ret += argv[i];
        }

        for (unsigned int i = 0; i < ret.length(); i++) {
            ret[i] = std::toupper(ret[i]);
        }
        std::cout << ret << "\n";
    } else {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    }
    return 0;
}