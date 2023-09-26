/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:57:29 by mneri             #+#    #+#             */
/*   Updated: 2023/09/26 15:01:01 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string dark_secret;
		std::string	phone_num;
	public:
    // Getter functions to access private member variables
    std::string getFirstName() const {
        return first_name;
    }

    std::string getLastName() const {
        return last_name;
    }

    std::string getNickName() const {
        return nick_name;
    }

    std::string getDarkSecret() const {
        return dark_secret;
    }

    std::string getPhoneNumber() const {
        return phone_num;
    }
	
	void setFirstName(const std::string& fname) {
        first_name = fname;
    }

    void setLastName(const std::string& lname) {
        last_name = lname;
    }

    void setNickName(const std::string& nname) {
        nick_name = nname;
    }

    void setDarkSecret(const std::string& secret) {
        dark_secret = secret;
    }

    void setPhoneNumber(const std::string& phone) {
        phone_num = phone;
    }
};

class PhoneBook
{
	public:
		Contact contact[8];
};