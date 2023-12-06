/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:00:31 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/06 17:58:05 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::complain(std::string level) const
{
	static std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	static void	(Harl::*methods[])(void) const = {&Harl::_debug,
		&Harl::_info, &Harl::_warning, &Harl::_error};
	
	for (int i = 0; i < 4; ++i)
		if (level == levels[i])
			return ((this->*methods[i])());
}

void	Harl::_debug(void) const
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}
void	Harl::_info(void) const
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void	Harl::_warning(void) const
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void	Harl::_error(void) const
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
