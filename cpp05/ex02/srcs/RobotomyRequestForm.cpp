/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:48:22 by nlegrand          #+#    #+#             */
/*   Updated: 2024/01/30 02:21:02 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Constants
const std::string	RobotomyRequestForm::defaultName = "RobotomyForm";
const std::string	RobotomyRequestForm::defaultTarget = "TargetName";

// Constructors
RobotomyRequestForm::RobotomyRequestForm(void) :
	AForm(defaultName, defaultGradeSign, defaultGradeExec),
	_target(defaultTarget) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& c) :
	AForm(c),
	_target(defaultTarget) {}
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	AForm(defaultName, defaultGradeSign, defaultGradeExec),
	_target(target) {}

// Destructors
RobotomyRequestForm::~RobotomyRequestForm(void) {};

// Operators
RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& c)
{
	if (this == &c)
		return (*this);
	AForm::operator=(c);
	return (*this);
}

// Utils
std::string	RobotomyRequestForm::getTarget(void) const
{ return (_target); }
void	RobotomyRequestForm::execAction(void) const
{
	int	random = rand() % 2;

	std::cout << "bbbbbzzzzzrrrrrrrtt...!! sscchrrrrrrtt..!! !@#$%&(T*Y#@" << std::endl;
	if (random)
		std::cout << _target << " has been robotomized! beep, boop!" << std::endl;
	else
		std::cout << "Failed to robotomize " << _target
			<< "... proceeding with the corpse disposal protocol." << std::endl;
}

// Stream Operators
std::ostream&	operator<<(std::ostream& os, const RobotomyRequestForm& f)
{
	os << f.getName() << ", form targeting " << f.getTarget()
		<< " with signing grade " << f.getGradeSign()
		<< " and executing grade " << f.getGradeExec() << " is ";
	if (f.getSigned() == false)
		os << "not ";
	os << "signed";
	return (os);
}
