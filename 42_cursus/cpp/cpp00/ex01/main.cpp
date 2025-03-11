#include "PhoneBook.hpp"
#include <iostream>

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin >> std::ws, command);
        if (std::cin.eof()) {
            std::cout << "\nExiting PhoneBook...\n";
            break;
        }
        if (command == "ADD") {
            phoneBook.add_Contact();
        }
		else if (command == "SEARCH") {
            phoneBook.search_Contact();
        }
		else if (command == "EXIT") {
            std::cout << "Exiting PhoneBook...\n";
			exit(0);
        }
		else {
            std::cout << "Invalid command!\n";
        }
    }

    return 0;
}