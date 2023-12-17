/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:56:38 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/17 16:49:12 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void	displayScalar(const t_scalar& sc)
{
	float			uselessff;
	double			uselessf;
	std::streamsize	defaultPrecision = std::cout.precision();

	// char
	if (sc.possible[SC_CHAR] && isprint(sc.c))
		std::cout << "char: '" << sc.c << "'" << std::endl;
	else if (sc.possible[SC_CHAR])
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;

	// int
	if (sc.possible[SC_INT])
		std::cout << "int: " << sc.i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

	static_cast<void>(uselessff);
	static_cast<void>(uselessf);
	// float
	std::cout << std::fixed;
	if (!isnan(sc.f) && !isinf(sc.f) && modff(sc.f, &uselessff) == 0) // will crash probably
		std::cout << std::setprecision(1);
	if (sc.possible[SC_FLOAT])
		std::cout << "float: " << sc.f << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl; // maybe this is nanf? idk

	// double // CHANGE FORMATTING, NO SCIENTIFIC NOTATION
	if (!isnan(sc.d) && !isinf(sc.d) && modf(sc.d, &uselessf) == 0) // will crash probably
		std::cout << std::setprecision(1);
	else
		std::cout << std::setprecision(static_cast<int>(defaultPrecision));
	if (sc.possible[SC_DOUBLE])
		std::cout << "double: " << sc.d << std::endl; // remove setw
	else
		std::cout << "double: impossible" << std::endl; // maybe this is nan? idk
}

static bool	isValidFormat(const std::string& f)
{
	if (f == "+inf" || f == "-inf"
			|| f == "+inff" || f == "-inff"
			|| f == "nan" || f == "nanf")
		return (true);
	int	i = 0;
	if (f[i] == '-' || f[i] == '+')
		++i;
	while (f[i] && isdigit(f[i]))
		++i;
	if (f[i] == '.')
		++i;
	while (f[i] && isdigit(f[i]))
		++i;
	if (f[i] == '\0' || (f[i] == 'f' && f[i + 1] == '\0'))
		return (true);
	return (false);

}

static void	convertFormat(t_scalar& scalar, const std::string& format)
{
	double	x = strtod(format.c_str(), NULL);

	// double
	if (errno)
	{
		scalar.possible[SC_DOUBLE] = false;
		errno = 0;
	}
	scalar.d = x;
	
	// char
	if (x < 0.0 || x > 127.0 || isinf(x) || isnan(x)) // NAN and inf?  
		scalar.possible[SC_CHAR] = false;
	scalar.c = static_cast<char>(x);

	// int
	if (x < static_cast<double>(INT_MIN) || x > static_cast<double>(INT_MAX)
			|| isinf(x) || isnan(x))
		scalar.possible[SC_INT] = false; // WHAT ABOUT nan and inf here???
	scalar.i = static_cast<int>(x);

	// float
	if (x < -HUGE_VALF || x > HUGE_VALF || scalar.possible[SC_DOUBLE] == false)
		scalar.possible[SC_FLOAT] = false;
	scalar.f = static_cast<float>(x);
	// IMPORTANT: Display overflows
}

// Utils
void	ScalarConverter::convert(const std::string& format)
{
	t_scalar	scalar;

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
	else if (isValidFormat(format))
		convertFormat(scalar, format);
	else
	{
		std::cout << "Error: Unknown scalar" << std::endl;
		return;
	}
	displayScalar(scalar); // PRECISION FOR DOUBLES IS FUCKED
}
