/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:47:20 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/08 23:50:27 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
public:
	// Constructors
	Form(void);
	Form(const Form& copy);
	Form(const std::string& name, bool sign, int gradeSign, int gradeExec);

	// Destructors
	~Form(void);

	// Operators
	Form&	operator<<(const Form& copy);

	// Getters/Setters
	std::string	getName(void) const;
	bool		getSigned(void) const;
	int			getGradeSign(void) const;
	int			getGradeExec(void) const;

	// Utils
	void	beSigned(const Bureaucrat& b);

	// Exceptions
	class	GradeTooHighException : public std::exception {
		virtual const char*	what() const throw();
	};
	class	GradeTooLowException : public std::exception {
		virtual const char*	what() const throw();
	};

	// Constants
	static const int	maxGrade = 1;
	static const int	minGrade = 150;

private:
	const std::string	_name;
	bool				_signed;
	const int			_gradeSign;
	const int			_gradeExec;
};

#endif // FORM_HPP
