/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:57:10 by nlegrand          #+#    #+#             */
/*   Updated: 2024/02/17 13:56:40 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <limits>
#include <cmath>


typedef enum e_scalarType
{
	SC_CHAR,
	SC_INT,
	SC_FLOAT,
	SC_DOUBLE,
	SC_INVALID
} t_scalarType;
typedef struct s_scalar
{
	t_scalarType		type;
	char				c;
	int					i;
	float				f;
	double				d;
	bool				possible[4];
} t_scalar;
typedef void (*convFun)(t_scalar&, const std::string&);

class ScalarConverter
{
public:
	// Destructors
	~ScalarConverter(void);

	// Utils
	static void	convert(const std::string& format);
private:
	// Constructor
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter& copy);

	// Operators
	ScalarConverter& operator=(const ScalarConverter& copy);
};

#endif // SCALAR_CONVERTER_HPP
