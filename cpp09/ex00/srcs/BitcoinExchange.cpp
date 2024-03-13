/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:01:49 by nlegrand          #+#    #+#             */
/*   Updated: 2024/02/21 18:33:54 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Destructors
BitcoinExchange::~BitcoinExchange(void) {}

// Uses stat to see if given filename corresponds to a regular file
static bool	isRegularFile(const std::string fileName)
{
	struct stat fileInfo;

	if (stat(fileName.c_str(), &fileInfo))
		return (false);
	return (S_ISREG(fileInfo.st_mode));
}

static void	myTrim(std::string& str)
{
	str.erase(0, str.find_first_not_of(' '));
	str.erase(str.find_last_not_of(' ') + 1);
}

static bool isValidDateFormat(const std::string& str)
{
	std::string	format = "dddd-dd-dd";

	if (str.size() != 10)
		return (false);
	for (int i = 0; i < 10; ++i)
	{
		if (format[i] == 'd' && !std::isdigit(str[i]))
			return (false);
		else if (format[i] == '-' && str[i] != '-')
			return (false);
	}
	return (true);
}

static bool isLeapYear(int year)
{
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}
static bool isShortMonth(int month)
{
	return (month == 4 || month == 6 || month == 9 || month == 11);
}

static bool	isValidDate(const std::string& str)
{
	std::istringstream	stream(str);
	int		year, month, day;
	char	sep;

	// check if str is of format YYYY-MM-DD
	if (!isValidDateFormat(str))
		return (false);

	// Extract date from string stream
	stream >> year >> sep >> month >> sep >> day;

	// Check date exists
	if (month == 00 || month > 12 || day == 00)
		return (false);
	if (month == 2 && day > 28 + isLeapYear(year))
		return (false);
	if (day > 31 - isShortMonth(month))
		return (false);
	return (true);
}

std::pair<std::string, double>	parseLine(const std::string& str, char sepChar)
{
	std::string::size_type			sep = str.find(sepChar);
	std::pair<std::string, double>	tmp;
	std::string						sub;
	char*							endptr = NULL;

	// check for separator
	if (sep == std::string::npos)
		throw std::runtime_error("Bad input `" + str + "'");

	// get date part
	sub = str.substr(0, sep);
	myTrim(sub);
	if (!isValidDate(sub))
		throw std::runtime_error("Bad date format `" + sub + "'");
	tmp.first = sub;

	// get number part
	sub = str.substr(sep + 1);
	myTrim(sub);
	tmp.second = std::strtod(sub.c_str(), &endptr);
	if (endptr && *endptr != '\0')
		throw std::runtime_error("Wrong number format `" + sub + "'");
	if (tmp.second != 0.0 && !std::isnormal(tmp.second))
		throw std::runtime_error("Number can't be represented `" + sub + "'");
	if (tmp.second > static_cast<double>(INT_MAX))
		throw std::runtime_error("Number too large `" + sub + "'");
	if (tmp.second < 0.0)
		throw std::runtime_error("Not a positive number `" + sub + "'");

	return (tmp);
}

// Goes through each line of the file, CSV format assumed
// if convert flag is false: populates data map
// if convert flag is true: converts the value instead using data map
static void	parseAndConvert(
	const std::string& fileName,
	std::map<std::string, double>& data,
	char sep,
	bool convert)
{
	std::ifstream									file(fileName.c_str());
	std::string										line;
	std::pair<std::string, double>					tmp;
	std::map<std::string, double>::const_iterator	it;

	// open file
	if (!isRegularFile(fileName))
		throw std::runtime_error("Data file missing or not a regular file");
	if (!file.is_open())
		throw std::runtime_error("Data file failed to open");
	// skip first line
	std::getline(file, line);

	// parse all lines
	while (std::getline(file, line))
	{
		if (!convert)
		{
			data.insert(parseLine(line, sep));
			continue;
		}
		try {
			tmp = parseLine(line, sep);
			if (tmp.first < data.begin()->first)
				throw std::runtime_error("No match in data");
			it = data.lower_bound(tmp.first);
			if (it == data.end() || it->first != tmp.first)
				--it;
			std::cout << tmp.first << " => " << tmp.second << " = " << tmp.second * it->second << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	file.close();
}

// Utils
void	BitcoinExchange::btc(const std::string dataName, const std::string inputName)
{
	std::map<std::string, double>	data;

	parseAndConvert(dataName, data, ',', false);
	if (data.size() == 0)
		throw std::runtime_error("No entries in data");
	parseAndConvert(inputName, data, '|', true);
}

// Constructors (private)
BitcoinExchange::BitcoinExchange(void) {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) { (void)copy; }

// Operators (private)
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy) { (void)copy; return (*this); }
