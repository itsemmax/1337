#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Contact {
	private :
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	public :
		void set_first_n(std::string str);
		void set_last_n(std::string str);
		void set_nickname(std::string str);
		void set_phone_number(std::string str);
		void set_secret(std::string str);
		std::string get_first_n();
		std::string get_last_n();
		std::string get_nickname();
		std::string get_phone_number();
		std::string get_secret();
};
#endif