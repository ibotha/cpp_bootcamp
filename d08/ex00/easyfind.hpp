#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>

template<typename T>
void easyfind(T container, int i)
{
    typename T::iterator it;

    it = find(container.begin(), container.end(), i);
    if (it != container.end())
        std::cout << "I found: " << *it << "!\n";
    else
    {
        throw std::exception();
    }
    
}

#endif