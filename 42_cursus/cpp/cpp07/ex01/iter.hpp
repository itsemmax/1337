#ifndef INTER_HPP
#define INTER_HPP

#include <iostream>


template <typename T, typename F>
void iter(T arr[], size_t len, F fct) {
	if(!arr || !fct)
		return;
	for (size_t i = 0; i < len; ++i) {
		fct(arr[i]);
	}
}
#endif