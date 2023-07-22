/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:00:31 by nlegrand          #+#    #+#             */
/*   Updated: 2023/07/22 14:36:53 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	this->_level = 1;
}

void	Harl::complain(std::string level) const
{
	static std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int					num;

	for (int i = 0; i < 4; ++i)
		if (level == levels[i])
		{
			num = i + 1;
			break;
		}

	switch (num)
	{
		case (1):
			this->_debug();
			break;
		case (2):
			this->_info();
			break;
		case (3):
			this->_warning();
			break;
		case (4):
			this->_error();
			break;
		default:
			std::cout << level << std::endl;
	}
}

void	Harl::setLevel(std::string level)
{
	if (level == "DEBUG")
		return ((void)(this->_level = 1));
	if (level == "INFO")
		return ((void)(this->_level = 2));
	if (level == "WARNING")
		return ((void)(this->_level = 3));
	if (level == "ERROR")
		return ((void)(this->_level = 4));
	return ((void)(this->_level = 0));

}

int	Harl::getLevel() const
{
	return (this->_level);
}

void	Harl::_debug(void) const
{
	if (this->_level > 1)
		return;
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}
void	Harl::_info(void) const
{
	if (this->_level > 2)
		return;
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void	Harl::_warning(void) const
{
	if (this->_level > 3)
		return;
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void	Harl::_error(void) const
{
	if (this->_level > 4)
		return;
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
