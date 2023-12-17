/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:56:38 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/16 17:53:10 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//static int	ft_isprint(char c)
//{ return (c >= ' ' && c <= 126); }
//
//static t_scalarType	getScalarType(const std::string& format)
//{
//	if (format.length() == 1)
//		return (SC_CHAR);
//	else if (match_int(format.c_str()))
//		return (SC_FLOAT);
//	else if (match_float(format.c_str()))
//		return SC_FLOAT;
//	else if (match_double(format.c_str()))
//	return (SC_INVALID);
//}
//
//static void	convChar(t_scalar& sc, const std::string& format)
//{
//	sc.c = format[0];
//	sc.i = static_cast<int>(sc.c);
//	sc.f = static_cast<float>(sc.c);
//	sc.d = static_cast<double>(sc.c);
//	sc.possible[0] = true;
//	sc.possible[1] = true;
//	sc.possible[2] = true;
//	sc.possible[3] = true;
//}

static void	displayScalar(const t_scalar& sc)
{
	// print char
	if (sc.possible[SC_CHAR] && isprint(sc.c))
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
		std::cout << std::setw(100) << std::right << "double: " << sc.d << std::endl; // remove setw
	else
		std::cout << "double: impossible" << std::endl; // maybe this is nan? idk
}

static bool	isValidFormat(const std::string& f)
{
	if (f == "inf" || f == "-inf" || f == "inff" || f == "-inff")
	int	i = 0;
	while (f[i])
}

// Utils
void	ScalarConverter::convert(const std::string& format)
{
	t_scalar		scalar;

	scalar.possible[0] = true; // remove
	scalar.possible[1] = true; // remove
	scalar.possible[2] = true; // remove
	scalar.possible[3] = true; // remove, or not maybe..?
	if (format.size() == 3 && format[0] == '\'' && format[2] == '\'')
	{
		scalar.c = format[1];
		scalar.i = static_cast<int>(scalar.c);
		scalar.f = static_cast<float>(scalar.c);
		scalar.d = static_cast<double>(scalar.c);
	}
	else
		(void)scalar; // convert things
	displayScalar(scalar); // PRECISION FOR DOUBLES IS FUCKED
}
