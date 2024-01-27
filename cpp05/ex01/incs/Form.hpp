/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:47:20 by nlegrand          #+#    #+#             */
/*   Updated: 2024/01/27 17:46:42 by nlegrand         ###   ########.fr       */
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
	Form(const std::string& name, int gradeSign, int gradeExec);

	// Destructors
	~Form(void);

	// Operators
	Form&	operator==(const Form& copy);

	// Getters/Setters
	std::string	getName(void) const;
	bool		getSigned(void) const;
	int			getGradeSign(void) const;
	int			getGradeExec(void) const;

	// Utils
	void	beSigned(const Bureaucrat& b);
	void	validateGrade(const int g) const;

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

// Stream Operators
std::ostream&	operator<<(std::ostream& os, const Form& f);

#endif // FORM_HPP
