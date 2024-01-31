/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 23:43:49 by nlegrand          #+#    #+#             */
/*   Updated: 2024/01/31 08:55:09 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
// Constructors
Intern::Intern(void) {}
Intern::Intern(const Intern& copy) { (void)copy; }
// Destructors
Intern::~Intern(void) {}

// Operators
Intern&	Intern::operator=(const Intern& copy)
{ (void)copy; return (*this); }

// Exceptions
const char*	Intern::InvalidFormName::what(void) const throw()
{ return ("invalid_form_name"); }

static AForm*	makePPForm(const std::string& target)
{ return (new PresidentialPardonForm(target)); }
static AForm*	makeSCForm(const std::string& target)
{ return (new ShrubberyCreationForm(target)); }
static AForm*	makeRRForm(const std::string& target)
{ return (new RobotomyRequestForm(target)); }

// Utils
AForm*	Intern::makeForm(const std::string& type, const std::string& target) const
{
	static const std::string	types[] = {"presidential pardon", "shrubbery creation", "robotomy request"};
	static AForm* (*const makeFunctions[])(const std::string&) = {makePPForm, makeSCForm, makeRRForm};
	AForm*	tmp;

	tmp = NULL;
	for (int i = 0; i < 3; ++i)
		if (type == types[i])
		{
			tmp = makeFunctions[i](target);
			return (tmp);
		}
	throw Intern::InvalidFormName();
	return (NULL);
}
