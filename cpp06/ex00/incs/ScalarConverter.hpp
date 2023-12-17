/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:57:10 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/14 15:32:33 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>


typedef enum e_scalarType
{
	SC_CHAR,
	SC_INT,
	SC_FLOAT,
	// IMPORTANT: Display overflows
	SC_DOUBLE,
	SC_INVALID
} t_scalarType;
typedef struct s_scalar
{
	t_scalarType		type;
	char				c;
	// IMPORTANT: Display overflows
	int					i;
	float				f;
	// IMPORTANT: Display overflows
	double				d;
	bool				possible[4];
} t_scalar;
typedef void (*convFun)(t_scalar&, const std::string&);

	// IMPORTANT: Display overflows
class ScalarConverter
{
public:
	// Utils
	static void	convert(const std::string& format); // IMPORTANT: Display overflows
private:
	// Constructor
	ScalarConverter(void);
};

#endif // SCALAR_CONVERTER_HPP
