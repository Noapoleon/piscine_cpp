/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:49:50 by nlegrand          #+#    #+#             */
/*   Updated: 2023/07/15 04:02:53 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

Contact::Contact(const Contact& copy)
{
	this->_firstName = copy._firstName;
	this->_lastName = copy._lastName;
	this->_nickname = copy._nickname;
	this->_phoneNumber = copy._phoneNumber;
	this->_darkestSecret = copy._darkestSecret;
}

std::string	Contact::_promptField(std::string prompt)
{
	std::string	input;

	while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (std::cin.eof())
			return ("");
		if (!input.empty())
			return (std::cin.clear(), input);
		std::cin.clear();
		std::cout << "This field cannot be blank, try again." << std::endl;
	}
}

void	Contact::promptInfo(void)
{
	this->_firstName = this->_promptField("First name: ");
	this->_lastName = this->_promptField("Last name: ");
	this->_nickname = this->_promptField("Nickname: ");
	this->_phoneNumber = this->_promptField("Phone number: ");
	this->_darkestSecret = this->_promptField("Darkest secret: ");
}

void	Contact::displayInfo(void) const
{
	std::cout << "First name: " << this->_firstName << std::endl;
	std::cout << "Last name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->_darkestSecret<< std::endl;
}

void	Contact::operator=(const Contact& copy)
{
	this->_firstName = copy._firstName;
	this->_lastName = copy._lastName;
	this->_nickname = copy._nickname;
	this->_phoneNumber = copy._phoneNumber;
	this->_darkestSecret = copy._darkestSecret;
}

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
