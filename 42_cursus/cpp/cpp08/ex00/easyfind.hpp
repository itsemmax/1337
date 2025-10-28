#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T container, int a)
{
    typename T::iterator it = std::find(container.begin(), container.end(), a);
    if (it == container.end())
        throw std::runtime_error("not found");
    return it;
}

#endif