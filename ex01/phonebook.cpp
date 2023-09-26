/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:05:43 by mneri             #+#    #+#             */
/*   Updated: 2023/09/26 15:34:49 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "phonebook.hpp"

void	add(PhoneBook *book, int i)
{
	std::string fname, lname, nname, dsecret, pnum;
	
	std::cout << "first name: ";
	std::cin >> fname;
	book->contact[i].setFirstName(fname);
	std::cout << "last name: ";
	std::cin >> lname;
	book->contact[i].setLastName(lname);
	std::cout << "nick name: ";
	std::cin >> nname;
	book->contact[i].setNickName(nname);
	std::cout << "dark secret: ";
	std::cin >> dsecret;
	book->contact[i].setDarkSecret(dsecret);
	std::cout << "phone number: ";
	std::cin >> pnum;
	book->contact[i].setPhoneNumber(pnum);

}

void	show_table(PhoneBook *book)
{
	int i;

	std::cout << std::setw(10) << "Index" << " | "
              << std::setw(10) << "First Name" << " | "
              << std::setw(10) << "Last Name" << " | "
              << std::setw(10) << "Nickname" << std::endl;
	for (i = 0; i < 8; i++)
	{
		std::cout << std::setw(10) << (i +1) << " | "
        << std::setw(10) << std::right << (book->contact[i].getFirstName().length() > 10 ? book->contact[i].getFirstName().substr(0, 9) + "." : book->contact[i].getFirstName()) << " | "
        << std::setw(10) << std::right << (book->contact[i].getLastName().length() > 10 ? book->contact[i].getLastName().substr(0, 9) + "." : book->contact[i].getLastName()) << " | "
        << std::setw(10) << std::right << (book->contact[i].getNickName().length() > 10 ? book->contact[i].getNickName().substr(0, 9) + "." : book->contact[i].getNickName()) << std::endl;
	}
	
}

void	index_select(PhoneBook *book)
{
	int index;
	std::cout << "Please select an index: ";
	std::cin >> index;
	if(index < 1 || index > 8)
	{
		std::cout << "Index not valid.";
		return;
	}
	else
	{
		std::cout << "First Name: " << book->contact[index - 1].getFirstName() << std::endl;
		std::cout << "Last Name: " << book->contact[index - 1].getLastName() << std::endl;
		std::cout << "Nick Name: " << book->contact[index - 1].getNickName() << std::endl;
		std::cout << "Dark secret: " << book->contact[index - 1].getDarkSecret() << std::endl;
		std::cout << "Phone number: " << book->contact[index - 1].getPhoneNumber() << std::endl;
	}
}

int main()
{
	PhoneBook book;
	std::string command;
	int i = 0;

	while(1)
	{
		std::cout << "\nADD to add contact | SEARCH to search contact | EXIT to exit program\n";
		std::cin >> command;
		if(command.compare("ADD") == 0)
		{
			add(&book, i);
			if(i != 7)
				i++;
		}
		else if(command.compare("SEARCH") == 0)
		{
			show_table(&book);
			index_select(&book);
			std::cin.clear();
		}
		else if(command.compare("EXIT") == 0)
		{
			return 1;
		}
	}

}
