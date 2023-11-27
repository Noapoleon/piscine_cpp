#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
public:
	// Constructors
	Bureaucrat(void);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat(const std::string& name, int grade);

	// Destructors
	~Bureaucrat(void);

	// Operators
	Bureaucrat&	operator=(const Bureaucrat& copy);

	// Getters / Setters
	int			getGrade(void) const;
	std::string	getName(void) const;

	// Utils
	void	incrementGrade(void);
	void	decrementGrade(void);

	// Exceptions
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
private:
	const std::string	_name;
	int					_grade;
};

// Stream operators
std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b);

#endif
