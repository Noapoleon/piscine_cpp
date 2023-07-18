/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:49:49 by nlegrand          #+#    #+#             */
/*   Updated: 2023/07/18 13:34:54 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include "utils.hpp"

class Contact
{
public:
	// Constructors
	Contact(void);
	Contact(const Contact& copy);

	// Destructor
	~Contact(void);

	// Operators
	void		operator=(const Contact& copy);

	// Getters / Setters
	std::string	getFirstName(void) const;
	std::string	getLastName(void) const;
	std::string	getNickname(void) const;
	std::string	getPhoneNumber(void) const;
	std::string	getDarkestSecret(void) const;

	// Utils
	void		displayInfo(void) const;
	void		promptInfo(void);

private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

	std::string	_promptField(std::string prompt);
};

#endif
