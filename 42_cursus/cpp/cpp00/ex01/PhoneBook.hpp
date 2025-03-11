#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

class PhoneBook{
	private:
		Contact contacts[8];
		int index;
		int a;
	public:
		PhoneBook();
		~PhoneBook();
		std::string check_input(std::string prompt, int a);
		std::string return_attr(std::string str);
		void add_Contact();
		void search_Contact();
};

#endif