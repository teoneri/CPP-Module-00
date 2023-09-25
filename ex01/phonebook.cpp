#include <iostream>
#include <iomanip>

class Contact
{
	public:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string dark_secret;
		std::string	phone_num;
};

class PhoneBook
{
	public:
		Contact contact[8];
};

void	add(PhoneBook *book, int i)
{
	std::cout << "first name: ";
	std::cin >> book->contact[i].first_name;
	std::cout << "last name: ";
	std::cin >> book->contact[i].last_name;
	std::cout << "nick name: ";
	std::cin >> book->contact[i].nick_name;
	std::cout << "dark secret: ";
	std::cin >> book->contact[i].dark_secret;
	std::cout << "phone number: ";
	std::cin >> book->contact[i].phone_num;

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
                  << std::setw(10) << std::right << (book->contact[i].first_name.length() > 10 ? book->contact[i].first_name.substr(0, 9) + "." : book->contact[i].first_name) << " | "
                  << std::setw(10) << std::right << (book->contact[i].last_name.length() > 10 ? book->contact[i].last_name.substr(0, 9) + "." : book->contact[i].last_name) << " | "
                  << std::setw(10) << std::right << (book->contact[i].nick_name.length() > 10 ? book->contact[i].nick_name.substr(0, 9) + "." : book->contact[i].nick_name) << std::endl;
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
		std::cout << "First Name: " << book->contact[index - 1].first_name << std::endl;
		std::cout << "Last Name: " << book->contact[index - 1].last_name << std::endl;
		std::cout << "Nick Name: " << book->contact[index - 1].nick_name << std::endl;
		std::cout << "Dark secret: " << book->contact[index - 1].dark_secret << std::endl;
		std::cout << "Phone number: " << book->contact[index - 1].phone_num << std::endl;
	}
}

int main()
{
	PhoneBook book;
	std::string command;
	int i = 0;
	int exit = 1;

	while(exit == 1)
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
		}
		else if(command.compare("EXIT") == 0)
		{
			return 1;
		}
	}

}
