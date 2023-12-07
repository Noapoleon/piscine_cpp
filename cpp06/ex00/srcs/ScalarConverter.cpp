/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:56:38 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/07 12:02:33 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static int	ft_isprint(char c)
{
	return (c >= ' ' && c <= 126);
	// IMPORTANT: Display overflows
}

static t_scalarType	getScalarType(const std::string& format)
{
	if (format.length() == 1)
		return (SC_CHAR);
	return (SC_INVALID);
}

static void	convChar(t_scalar& sc, const std::string& format)
{
	sc.c = format[0];
	sc.i = static_cast<int>(sc.c); // dynamic cast later or something?
	sc.f = static_cast<float>(sc.c); // dynamic cast later or something?
	sc.d = static_cast<double>(sc.c); // dynamic cast later or something?
	sc.possible[0] = true;
	sc.possible[1] = true;
	sc.possible[2] = true;
	sc.possible[3] = true;
}

static void	displayScalar(const t_scalar& sc)
{
	// print char
	if (sc.possible[SC_CHAR] && ft_isprint(sc.c))
		std::cout << "char: '" << sc.c << "'" << std::endl;
	else if (sc.possible[SC_CHAR])
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;

	// print int
	if (sc.possible[SC_INT])
		std::cout << "int: " << sc.i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

	// print float
	if (sc.possible[SC_FLOAT])
		std::cout << "float: " << sc.f << std::endl;
	else
		std::cout << "float: impossible" << std::endl; // maybe this is nanf? idk

	// print double
	if (sc.possible[SC_DOUBLE])
		std::cout << "double: " << sc.d << std::endl;
	else
		std::cout << "double: impossible" << std::endl; // maybe this is nan? idk
}

// Utils
void	ScalarConverter::convert(const std::string& format)
{
	//static const	convFun[] = {convChar, convInt, convFloat, convDouble};
	static const convFun	convs[] = {convChar};
	t_scalar		scalar;

	// IMPORTANT: Display overflows
	scalar.type  = getScalarType(format);
	if (scalar.type == SC_INVALID) // remove later
		return ((void)(std::cout << "The fuck you did?" << std::endl));
	convs[scalar.type](scalar, format);
	displayScalar(scalar);
}
