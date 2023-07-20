/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:36:42 by nlegrand          #+#    #+#             */
/*   Updated: 2023/07/21 00:59:59 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

static int	is_valid_file(char *path)
{
	struct stat	buffer;

	if (stat(path, &buffer) == 0)
		return (!(buffer.st_mode & S_IFDIR));
	return (0);
}

static int	push_substitute(std::ifstream &ifs, std::ofstream &ofs,
	char *s1, char *s2)
{
	std::string	save;
	int			i;
	char		c;

	save.push_back(s1[0]);
	i = 1;
	while (1)
	{
		if (s1[i] == '\0')
		{
			ofs << std::string(s2);
			if (ofs.fail())
				return (-1);
			save.clear();
			break ;
		}
		if (!(ifs >> c))
			break ;
		save.push_back(c);
		if (c != s1[i])
		{
			ofs << save;
			if (ofs.fail())
				return (-1);
			save.clear();
			break ;
		}
		++i;
	}
	if (ifs.fail())
		return (-1);
	return (0);
}

static int	replace(std::ifstream &ifs, std::ofstream &ofs,
	char *s1, char *s2)
{
	char		c;

	ifs >> std::noskipws;
	while (ifs >> c)
	{
		if (c == s1[0])
		{
			if (push_substitute(ifs, ofs, s1, s2) != 0)
				return (-1);
		}
		else
		{
			ofs << c;
			if (ofs.fail())
				return (-1);
		}
	}
	ofs << std::flush;
	if (ofs.fail())
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		ofs_name;
	int				ret;

	// Check args
	errno = 0;
	if (ac != 4)
		return (std::cout << "Usage: " << av[0] << " <file> <s1> <s2>"
			<< std::endl, 1);

	// Open input
	if (!is_valid_file(av[1]))
		return (std::cout << av[0] << ": " << av[1] << ": Not a valid file"
			<< std::endl, 1);
	ifs.open(av[1], std::ifstream::in);
	if (!ifs.good())
		return (std::cout << av[0] << ": " << av[1] << ": " << strerror(errno)
			<< std::endl, 1);

	// Create output
	ofs_name = std::string(av[1]) + ".replace";
	ofs.open(ofs_name.c_str(), std::ofstream::out | std::ofstream::trunc);
	if (!ofs.good())
		return (std::cout << av[0] << ": " << ofs_name << ": "
			<< strerror(errno) << std::endl, 1);
	ret = replace(ifs, ofs, av[2], av[3]);
	ifs.close();
	ofs.close();
	if (ret != 0)
		return (unlink(ofs_name.c_str()), std::cout << av[0] << ": " << ofs_name
			<< ": " << strerror(errno) << std::endl, 1);
	return (0);
}
