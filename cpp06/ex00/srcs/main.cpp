/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:39:57 by nlegrand          #+#    #+#             */
/*   Updated: 2024/02/17 13:30:31 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <climits>
#include <cerrno>
#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Wrong arguments, fool!~" << std::endl;
		if (ac == 1)
			std::cout << "Usage: " << av[0] << " <scalar>" << std::endl;
		return (1);
	}

	errno = 0;
	ScalarConverter::convert(std::string(av[1]));
	return (0);
}
