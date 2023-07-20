/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 02:04:51 by nlegrand          #+#    #+#             */
/*   Updated: 2023/07/20 21:06:15 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

// Clears the std::cin after an input
void	clear_cin(void)
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Prints warning message and returns true if std::cin reached an EOF
bool	reachedEof(void)
{
	if (std::cin.eof())
	{
		std::cout << "\n\e[1;38;2;255;0;0mEnd-Of-File reached...\e[0m"
			<< std::endl;
		return (true);
	}
	return (false);
}

std::string	truncField(std::string str)
{
	if (str.length() < 10)
		return (str); // not sure i can do that
	return (str.substr(0, 9) + ".");
}

int	is_valid_phone(std::string &str)
{
	int	len = str.length();

	if (str.length() != 10)
		return (0);
	for (int i = 0; i < len; ++i)
		if (!std::isdigit(str[i]))
			return (0);
	return (1);
}
