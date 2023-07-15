/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:25:03 by nlegrand          #+#    #+#             */
/*   Updated: 2023/07/15 04:21:01 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <iostream>
#include <limits>
#include <iomanip>
#include "Contact.hpp"
#include "utils.hpp"

class PhoneBook
{
public:
	PhoneBook(void);
	PhoneBook(const PhoneBook& copy);
	~PhoneBook(void);

	void	add(void);
	void	search(void) const;
	void	displayContacts(void) const;
private:
	Contact	_contacts[8];
	int		_index;
	int		_numberContacts;
	int		_promptIndex(std::string prompt) const;
	void	_displayBanner(void) const;
};

#endif


// add ADD prompt
//
