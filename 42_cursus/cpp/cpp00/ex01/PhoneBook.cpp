#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){index = 0; a = 0;}

std::string PhoneBook::check_input(std::string prompt, int a)
{
	std::string str;
	int i ;
	std::cout << "please enter " << prompt << ":" ;
	std::getline(std::cin,str);
	if (std::cin.eof()) {
        exit(1);
    }
	if(str.empty())
	{
		std::cout << "error , a field can't be empty" << std::endl;
		return check_input(prompt,a);
	}
	if(a == 2)
	{
		i = 0;
		while(i < (int)str.length())
		{
			if(!std::isdigit(str[i]))
			{
				std::cout << "Invalid phone number. Please enter only digits" << std::endl;
				return check_input(prompt,a);
			}
			i++;
		}
	}
	return str;
}

void PhoneBook::add_Contact() {
    Contact newContact;
	static int count = 0;
	newContact.set_first_n(check_input("first name", 1));
    newContact.set_last_n(check_input("last name", 1));
    newContact.set_nickname(check_input("nickname", 1));
    newContact.set_phone_number(check_input("phonenumber", 2));
    newContact.set_secret(check_input("darkest secret", 1));

	contacts[count % 8] = newContact;
	count++;
	if(index < 8)
		index++;
    std::cout << "Contact added successfully!\n";
}

std::string PhoneBook::return_attr(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void PhoneBook::search_Contact()
{
	int i;
	int user_index;

	if (index == 0)
	{
		std::cout << "Phonebook is empty!\n";
		return;
	}
    std::cout << "-----------------Phonebook-----------------\n";
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << "\n";

	i = 0;
	while (i < index)
	{
		std::cout << std::setw(10) << i << "|"
				  << std::setw(10) << return_attr(contacts[i].get_first_n()) << "|"
				  << std::setw(10) << return_attr(contacts[i].get_last_n()) << "|"
				  << std::setw(10) << return_attr(contacts[i].get_nickname()) << "\n";

		i++;
	}
    std::cout << "--------------------------------------------\n";
	std::cout << "Enter index of contact to display:";
	if (!(std::cin >> user_index) || user_index < 0 || user_index >= index)
	{
		if (std::cin.eof())
		{
			std::cout << "\nEOF detected. Exiting...\n";
			exit(1);
		}
		std::cout << "Invalid index! Please enter a number between 0 and " << index - 1<< ": \n";
		std::cin.clear();  
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		
		return search_Contact();
	}
	else
	{
			std::cout << "First Name: " << return_attr(contacts[user_index].get_first_n()) << "\n"
			  << "Last Name: " << return_attr(contacts[user_index].get_last_n()) << "\n"
			  << "Nickname: " << return_attr(contacts[user_index].get_nickname()) << "\n"
			  << "Phone Number: " << return_attr(contacts[user_index].get_phone_number()) << "\n"
			  << "Darkest Secret: " << return_attr(contacts[user_index].get_secret()) << "\n";

	}
}
PhoneBook::~PhoneBook(){}