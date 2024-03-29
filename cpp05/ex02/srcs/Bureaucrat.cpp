/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:59:22 by nlegrand          #+#    #+#             */
/*   Updated: 2024/01/29 23:07:11 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Constructors
Bureaucrat::Bureaucrat(void) : _name("Ritupon Baishya"), _grade(minGrade)
{ validateGrade(_grade); }
Bureaucrat::Bureaucrat(const Bureaucrat& copy)
	: _name(copy._name), _grade(copy._grade)
{ validateGrade(_grade); }
Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: _name(name), _grade(grade)
{ validateGrade(_grade); }

// Destructors
Bureaucrat::~Bureaucrat(void) {}

// Operators
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& copy)
{
	if (this == &copy)
		return (*this);
	_grade = copy._grade;
	return (*this);
}

// Getters / Setters
int	Bureaucrat::getGrade(void) const
{ return (_grade); }
std::string	Bureaucrat::getName(void) const
{ return (_name); }

// Utils
void	Bureaucrat::incrementGrade(void)
{
	validateGrade(_grade - 1);
	--_grade;
}
void	Bureaucrat::decrementGrade(void)
{
	validateGrade(_grade + 1);
	++_grade;
}
void	Bureaucrat::validateGrade(const int g) const
{
	if (g < maxGrade)
		throw GradeTooHighException();
	if (g > minGrade)
		throw GradeTooLowException();
}
void	Bureaucrat::signForm(AForm& f) const
{
	try {
		f.beSigned(*this);
	} catch (std::exception& e) {
		std::cout << _name << " couldn't sign " << f.getName()
			<< " because " << e.what() << std::endl;
		return;
	}
	std::cout << _name << " signed " << f.getName() << std::endl;
}
void	Bureaucrat::executeForm(const AForm& f) const
{
	try
	{
		f.execute(*this);
	}
	catch (const std::exception& e)
	{
		std::cout << _name << " failed to execute " << f.getName()
			<< " because " << e.what() << std::endl;
		return;
	}
	std::cout << _name << " executed " << f.getName() << std::endl;
}

// Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw()
{ return ("grade_too_high"); }
const char* Bureaucrat::GradeTooLowException::what() const throw()
{ return ("grade_too_low"); }

// Stream operators
std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}
