/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:47:04 by nlegrand          #+#    #+#             */
/*   Updated: 2024/01/27 17:52:15 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructors
Form::Form(void) :
	_name("DefaultName"),
	_signed(false),
	_gradeSign(Form::maxGrade),
	_gradeExec(Form::maxGrade)
{
	validateGrade(_gradeSign);
	validateGrade(_gradeExec);
}
Form::Form(const Form& copy) :
	_name(copy._name),
	_signed(copy._signed),
	_gradeSign(copy._gradeSign),
	_gradeExec(copy._gradeExec)
{
	validateGrade(_gradeSign);
	validateGrade(_gradeExec);
}
Form::Form(const std::string& name, int gradeSign, int gradeExec) :
	_name(name),
	_signed(false),
	_gradeSign(gradeSign),
	_gradeExec(gradeExec)
{
	validateGrade(_gradeSign);
	validateGrade(_gradeExec);
}

// Destructors
Form::~Form(void) {}

// Operators
Form& Form::operator==(const Form& copy)
{
	if (this == &copy)
		return (*this);
	_signed = copy._signed;
	return (*this);
}

// Getters/Setters
std::string	Form::getName(void) const
{ return (_name); };
bool	Form::getSigned(void) const
{ return (_signed); }
int		Form::getGradeSign(void) const
{ return (_gradeSign); }
int		Form::getGradeExec(void) const
{ return (_gradeExec); }

// Utils
void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _gradeSign)
		throw Form::GradeTooLowException();
	_signed = 1;
}
void	Form::validateGrade(const int g) const
{
	if (g < maxGrade)
		throw GradeTooHighException();
	if (g > minGrade)
		throw GradeTooLowException();
}

// Exceptions
const char* Form::GradeTooHighException::what() const throw()
{ return ("grade_too_high"); }
const char* Form::GradeTooLowException::what() const throw()
{ return ("grade_too_low"); }

// Stream Operators
std::ostream&	operator<<(std::ostream& os, const Form& f)
{
	os << f.getName() << ", form signing grade " << f.getGradeSign()
		<< " and executing grade " << f.getGradeExec() << " is ";
	if (f.getSigned() == false)
		os << "not ";
	os << "signed";
	return (os);
}
