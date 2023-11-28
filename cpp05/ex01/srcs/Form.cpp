/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:47:04 by nlegrand          #+#    #+#             */
/*   Updated: 2023/11/28 20:18:56 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructors
Form::Form(void) :
	_name("DefaultName"),
	_signed(0),
	_gradeSign(Form::maxGrade),
	_gradeExec(Form::maxGrade)
{
	if (_gradeSign < Form::maxGrade || _gradeExec < Form::maxGrade)
		throw Form::GradeTooHighException();
	if (_gradeSign > Form::minGrade || _gradeExec > Form::minGrade)
		throw Form::GradeTooLowException();
}
Form::Form(const Form& copy) :
	_name(copy._name),
	_signed(copy._signed),
	_gradeSign(copy._gradeSign),
	_gradeExec(copy._gradeExec)
{
	if (_gradeSign < Form::maxGrade || _gradeExec < Form::maxGrade)
		throw Form::GradeTooHighException();
	if (_gradeSign > Form::minGrade || _gradeExec > Form::minGrade)
		throw Form::GradeTooLowException();
}
Form::Form(const std::string& name, bool sign, int gradeSign, int gradeExec) :
	_name(name),
	_signed(sign),
	_gradeSign(gradeSign),
	_gradeExec(gradeExec)
{
	if (_gradeSign < Form::maxGrade || _gradeExec < Form::maxGrade)
		throw Form::GradeTooHighException();
	if (_gradeSign > Form::minGrade || _gradeExec > Form::minGrade)
		throw Form::GradeTooLowException();
}

// Destructors
Form::~Form(void) {}

// Operators
Form& Form::operator<<(const Form& copy)
{
	if (this == &copy)
		return (*this);
	_signed = copy._signed;
	return (*this);
}

// Getters/Setters
std::string	Form::getName(void) const
{
	return (_name);
};
bool	Form::getSigned(void) const
{
	return (_signed);
}
int		Form::getGradeSign(void) const
{
	return (_gradeSign);
}
int		Form::getGradeExec(void) const
{
	return (_gradeExec);
}

// Utils
void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _gradeSign)
		throw Form::GradeTooLowException();
	_signed = 1;
}

// Exceptions
const char* Form::GradeTooHighException::what() const throw()
{ return ("grade_too_high"); }
const char* Form::GradeTooLowException::what() const throw()
{ return ("grade_too_low"); }
