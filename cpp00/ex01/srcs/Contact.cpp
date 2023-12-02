/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:49:50 by nlegrand          #+#    #+#             */
/*   Updated: 2023/07/20 21:06:48 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Constructors
Contact::Contact() {}
Contact::Contact(const Contact& copy)
{
	*this = copy;
}

// Destructors
Contact::~Contact() {}

// Operators
void	Contact::operator=(const Contact& copy)
{
	if (this == &copy)
		return;
	this->_firstName = copy._firstName;
	this->_lastName = copy._lastName;
	this->_nickname = copy._nickname;
	this->_phoneNumber = copy._phoneNumber;
	this->_darkestSecret = copy._darkestSecret;
}

// Getters / Setters
std::string	Contact::getFirstName(void) const
{
	return this->_firstName;
}
std::string	Contact::getLastName(void) const
{
	return this->_lastName;
}
std::string	Contact::getNickname(void) const
{
	return this->_nickname;
}
std::string	Contact::getPhoneNumber(void) const
{
	return this->_phoneNumber;
}
std::string	Contact::getDarkestSecret(void) const
{
	return this->_darkestSecret;
}

// Utils
std::string	Contact::_promptField(std::string prompt, int digits)
{
	std::string	input;

	while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (std::cin.eof())
			return ("");
		if (!input.empty())
		{
			if (digits && is_valid_phone(input))
				return (std::cin.clear(), input);
			if (!digits)
				return (std::cin.clear(), input);
		}
		std::cin.clear();
		std::cout << "Invalid input, try again." << std::endl;
	}
}
void	Contact::promptInfo(void)
{
	this->_firstName = this->_promptField("First name: ", 0);
	this->_lastName = this->_promptField("Last name: ", 0);
	this->_nickname = this->_promptField("Nickname: ", 0);
	this->_phoneNumber = this->_promptField("Phone number (10 digits exactly): ", 1);
	this->_darkestSecret = this->_promptField("Darkest secret: ", 0);
}
void	Contact::displayInfo(void) const
{
	std::cout << "First name: " << this->_firstName << std::endl;
	std::cout << "Last name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->_darkestSecret<< std::endl;
}
