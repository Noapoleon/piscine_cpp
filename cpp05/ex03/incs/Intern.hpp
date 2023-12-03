/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 00:05:37 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/03 01:30:39 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	// Constructors
	Intern(void);
	Intern(const Intern& copy);
	// Destructors
	~Intern(void);

	// Operators
	Intern&	operator=(const Intern& copy);

	// Exceptions
	class InvalidFormName : public std::exception {
		public:
			virtual const char*	what(void) const throw();
	};

	// Utils
	AForm*	makeForm(const std::string& type, const std::string& target) const;
};

#endif
