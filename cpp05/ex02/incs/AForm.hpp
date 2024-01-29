/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:47:20 by nlegrand          #+#    #+#             */
/*   Updated: 2024/01/29 22:28:09 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class AForm
{
public:
	// Constructors
	AForm(void);
	AForm(const AForm& copy);
	AForm(const std::string& name, int gradeSign, int gradeExec);

	// Destructors
	~AForm(void);

	// Operators
	AForm&	operator=(const AForm& copy);

	// Getters/Setters
//	std::string	getTarget(void) const;
	std::string	getName(void) const;
	bool		getSigned(void) const;
	int			getGradeSign(void) const;
	int			getGradeExec(void) const;

	// Utils
	void			beSigned(const Bureaucrat& b);
	void			validateGrade(const int g) const;
	void			execute(const Bureaucrat& executor) const;
	virtual void	execAction(void) const = 0;


	// Exceptions
	class	GradeTooHighException : public std::exception {
		virtual const char*	what() const throw();
	};
	class	GradeTooLowException : public std::exception {
		virtual const char*	what() const throw();
	};
	class	FormNotSignedException : public std::exception {
		virtual const char*	what() const throw();
	};

	// Constants
	static const int	maxGrade = 1;
	static const int	minGrade = 150;

//protected:
//	std::string	_target; // CHECK WHY THIS IS PROTECTED AGAIN
private:
	const std::string	_name;
	bool				_signed;
	const int			_gradeSign;
	const int			_gradeExec;
};

// Stream Operators
std::ostream&	operator<<(std::ostream& os, const AForm& f);

#endif // AFORM_HPP
