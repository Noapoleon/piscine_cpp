#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat(void) : _name("Ritupon Baishya"), _grade(150) {}
Bureaucrat::Bureaucrat(const Bureaucrat& copy)
	: _name(copy._name), _grade(copy._grade) {}
Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: _name(name), _grade(grade) {}

// Destructors
Bureaucrat::~Bureaucrat(void) {}

// Operators
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& copy)
{
	if (this == &copy)
		return (*this);
	this->_grade = copy._grade;
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

// Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}
