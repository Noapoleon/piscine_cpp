/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:47:04 by nlegrand          #+#    #+#             */
/*   Updated: 2024/01/30 02:08:55 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructors
AForm::AForm(void) :
	_name("DefaultName"),
	_signed(false),
	_gradeSign(maxGrade),
	_gradeExec(maxGrade)
{
	validateGrade(_gradeSign);
	validateGrade(_gradeExec);
}
AForm::AForm(const AForm& copy) :
	_name(copy._name),
	_signed(false),
	_gradeSign(copy._gradeSign),
	_gradeExec(copy._gradeExec)
{
	validateGrade(_gradeSign);
	validateGrade(_gradeExec);
}
AForm::AForm(const std::string& name, int gradeSign, int gradeExec) :
	_name(name),
	_signed(false),
	_gradeSign(gradeSign),
	_gradeExec(gradeExec)
{
	validateGrade(_gradeSign);
	validateGrade(_gradeExec);
}

// Destructors
AForm::~AForm(void) {}

// Operators
AForm& AForm::operator=(const AForm& copy)
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

// Utils
void	AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _gradeSign)
		throw GradeTooLowException();
	_signed = 1;
}
void	AForm::validateGrade(const int g) const
{
	if (g < maxGrade)
		throw GradeTooHighException();
	if (g > minGrade)
		throw GradeTooLowException();
}
void	AForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > _gradeExec)
		throw GradeTooLowException();
	if (this->getSigned() == false)
		throw FormNotSignedException();
	this->execAction();
}

// Exceptions
const char* AForm::GradeTooHighException::what() const throw()
{ return ("grade_too_high"); }
const char* AForm::GradeTooLowException::what() const throw()
{ return ("grade_too_low"); }
const char*	AForm::FormNotSignedException::what() const throw()
{ return ("form_not_signed"); }

// Stream Operators
std::ostream&	operator<<(std::ostream& os, const AForm& f)
{
	os << f.getName() << ", form with signing grade " << f.getGradeSign()
		<< " and executing grade " << f.getGradeExec() << " is ";
	if (f.getSigned() == false)
		os << "not ";
	os << "signed";
	return (os);
}
