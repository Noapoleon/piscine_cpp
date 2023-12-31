/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:47:04 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/02 22:24:49 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructors
AForm::AForm(void) :
	_name("DefaultName"),
	_signed(0),
	_gradeSign(AForm::maxGrade),
	_gradeExec(AForm::maxGrade)
{
	std::cout << "AForm constructor" << std::endl;
	if (_gradeSign < AForm::maxGrade || _gradeExec < AForm::maxGrade)
		throw AForm::GradeTooHighException();
	if (_gradeSign > AForm::minGrade || _gradeExec > AForm::minGrade)
		throw AForm::GradeTooLowException();
}
AForm::AForm(const AForm& copy) :
	_name(copy._name),
	_signed(copy._signed),
	_gradeSign(copy._gradeSign),
	_gradeExec(copy._gradeExec)
{
	if (_gradeSign < AForm::maxGrade || _gradeExec < AForm::maxGrade)
		throw AForm::GradeTooHighException();
	if (_gradeSign > AForm::minGrade || _gradeExec > AForm::minGrade)
		throw AForm::GradeTooLowException();
}
AForm::AForm(const std::string& name, bool sign, int gradeSign, int gradeExec) :
	_name(name),
	_signed(sign),
	_gradeSign(gradeSign),
	_gradeExec(gradeExec)
{
	if (_gradeSign < AForm::maxGrade || _gradeExec < AForm::maxGrade)
		throw AForm::GradeTooHighException();
	if (_gradeSign > AForm::minGrade || _gradeExec > AForm::minGrade)
		throw AForm::GradeTooLowException();
}

// Destructors
AForm::~AForm(void) {}

// Operators
AForm& AForm::operator<<(const AForm& copy)
{
	if (this == &copy)
		return (*this);
	_signed = copy._signed;
	return (*this);
}

// Getters/Setters
std::string	AForm::getName(void) const
{ return (_name); }
bool	AForm::getSigned(void) const
{ return (_signed); }
int		AForm::getGradeSign(void) const
{ return (_gradeSign); }
int		AForm::getGradeExec(void) const
{ return (_gradeExec); }
std::string	AForm::getTarget(void) const
{ return (_target); }

// Utils
void	AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _gradeSign)
		throw AForm::GradeTooLowException();
	_signed = 1;
}
void	AForm::checkExec(const Bureaucrat& executor) const
{
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	if (!this->getSigned())
	{
		throw AForm::FormNotSignedException();
	}
}

// Exceptions
const char* AForm::GradeTooHighException::what() const throw()
{ return ("grade_too_high"); }
const char* AForm::GradeTooLowException::what() const throw()
{ return ("grade_too_low"); }
const char*	AForm::FormNotSignedException::what() const throw()
{ return ("form_not_signed"); }
