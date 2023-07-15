/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:25:04 by nlegrand          #+#    #+#             */
/*   Updated: 2023/07/15 04:26:24 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_displayBanner();
	std::cout << "\e[1;4mCommands:\e[0m" << std::endl;
	std::cout << "- ADD: save a new contact" << std::endl;
	std::cout << "- SEARCH: display a specific contact" << std::endl;
	std::cout << "- EXIT: close My Awesome Phonebook" << std::endl;

	this->_index = 0;
	this->_numberContacts = 0;
}

PhoneBook::PhoneBook(const PhoneBook& copy)
{
	this->_index = copy._index;
	this->_numberContacts = copy._numberContacts;

	for (int i = 0; i < 8; ++i)
		this->_contacts[i] = copy._contacts[i];
}

PhoneBook::~PhoneBook(void)
{
	this->_displayBanner();
}

void	PhoneBook::_displayBanner(void) const
{
	std::cout << "\e[1;38;2;255;0;255m------------------------" << std::endl;
	std::cout << "| My Awesome PhoneBook |" << std::endl;
	std::cout << "------------------------\e[0m" << std::endl;
}

void	PhoneBook::add(void)
{
	Contact		tmp;
	std::string	input;

	// Prompt new contact
	tmp.promptInfo();

	// Save prompting
	while (true)
	{
		std::cout << "Do you want to save this contact? [Y/n] ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return;
		if (input.empty() || input == "y" || input == "Y")
		{
			std::cout << "Saved new contact to list!" << std::endl;
			std::cin.clear();
			break;
		}
		else if (input == "n")
		{
			std::cout << "Discarded contact..." << std::endl;
			return ((void)std::cin.clear());
		}
		std::cin.clear();
		std::cout << "Wrong input, try again." << std::endl;
	}

	// Save new contact and increment
	this->_contacts[this->_index] = tmp;
	if (++this->_index >= 8)
		this->_index %= 8;
	if (this->_numberContacts < 8)
		++this->_numberContacts;
}

void	PhoneBook::search(void) const
{
	int	index;

	if (this->_numberContacts == 0)
	{
		std::cout << "No contacts saved, cancelling search..." << std::endl;
		return;
	}

	// Display contacts in board
	this->displayContacts();
	
	// prompt index
	while (true)
	{
		index = this->_promptIndex("Enter contact index: ");
		if (std::cin.eof())
			return;
		if (index == -1)
		{
			std::cout << "Cancelling search..." << std::endl;
			return;
		}
		if (this->_numberContacts != 0 && index >= 0 &&
			index <= this->_numberContacts - 1)
			break;
		std::cout << "Invalid index, try again. (-1 to cancel)" << std::endl;
	}

	// display contact
	std::cout << std::endl;
	this->_contacts[index].displayInfo();
}

int	PhoneBook::_promptIndex(std::string prompt) const
{
	int	index;

	while (true)
	{
		std::cout << prompt;
		std::cin >> index;
		if (std::cin.eof())
			return (-2);
		if (!std::cin.fail())
			return (clear_cin(), index);
		clear_cin();
		std::cout << "Not a number, try again. (-1 to cancel)" << std::endl;
	}
}

void	PhoneBook::displayContacts(void) const
{
	std::cout << std::setw(10) << std::right << "Index";
	std::cout << "|" << std::setw(10) << std::right << "First Name";
	std::cout << "|" << std::setw(10) << std::right << "Last Name";
	std::cout << "|" << std::setw(10) << std::right << "Nickname" << std::endl;
	for (int i = 0; i < this->_numberContacts; ++i)
	{
		std::cout << std::setw(10) << std::right << i;
		std::cout << "|" << std::setw(10) << std::right
			<< truncField(this->_contacts[i].getFirstName());
		std::cout << "|" << std::setw(10) << std::right
			<< truncField(this->_contacts[i].getLastName());
		std::cout << "|" << std::setw(10) << std::right
			<< truncField(this->_contacts[i].getNickname()) << std::endl;
	}
}
