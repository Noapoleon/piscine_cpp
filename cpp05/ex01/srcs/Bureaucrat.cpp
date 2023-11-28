/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:59:22 by nlegrand          #+#    #+#             */
/*   Updated: 2023/11/28 21:09:51 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// Constructors
Bureaucrat::Bureaucrat(void) : _name("Ritupon Baishya"), _grade(150)
{
	if (_grade < Bureaucrat::maxGrade)
		throw Bureaucrat::GradeTooHighException();
	if (_grade > Bureaucrat::minGrade)
		throw Bureaucrat::GradeTooLowException();
}
Bureaucrat::Bureaucrat(const Bureaucrat& copy)
	: _name(copy._name), _grade(copy._grade)
{
	if (_grade < Bureaucrat::maxGrade)
		throw Bureaucrat::GradeTooHighException();
	if (_grade > Bureaucrat::minGrade)
		throw Bureaucrat::GradeTooLowException();
}
Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: _name(name), _grade(grade)
{
	if (_grade < Bureaucrat::maxGrade)
		throw Bureaucrat::GradeTooHighException();
	if (_grade > Bureaucrat::minGrade)
		throw Bureaucrat::GradeTooLowException();
}

// Destructors
Bureaucrat::~Bureaucrat(void) {}

// Operators
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& copy)
{
	if (this == &copy)
		return (*this);
	_grade = copy._grade;
	// _name = copy._name; // name is const, there are ways to change it still with const_cast but should I? People online saying it's UB and very bad depending on certain compiler optimizations
	return (*this);
}

// Getters / Setters
int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}
std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

// Utils
void	Bureaucrat::incrementGrade(void)
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	--(_grade);
}
void	Bureaucrat::decrementGrade(void)
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	++(_grade);
}
void	Bureaucrat::signForm(Form& f) const
{
	try
	{
		f.beSigned(*this);
	}
	catch (std::exception& e)
	{
		std::cout << _name << " coudln't sign " << f.getName()
			<< " because " << e.what() << std::endl;
	}
	std::cout << _name << " signed " << f.getName() << std::endl;
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
