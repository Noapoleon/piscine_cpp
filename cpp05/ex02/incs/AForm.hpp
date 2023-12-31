/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:47:20 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/02 22:22:13 by nlegrand         ###   ########.fr       */
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
	AForm(const std::string& name, bool sign, int gradeSign, int gradeExec);

	// Destructors
	~AForm(void);

	// Operators
	AForm&	operator<<(const AForm& copy);

	// Getters/Setters
	std::string	getName(void) const;
	bool		getSigned(void) const;
	int			getGradeSign(void) const;
	int			getGradeExec(void) const;
	std::string	getTarget(void) const;

	// Utils
	void			beSigned(const Bureaucrat& b);
	virtual	void	execute(const Bureaucrat& executor) const = 0;
	void			checkExec(const Bureaucrat& executor) const;

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

protected:
	std::string	_target;
private:
	const std::string	_name;
	bool				_signed;
	const int			_gradeSign;
	const int			_gradeExec;
};

#endif // AFORM_HPP
