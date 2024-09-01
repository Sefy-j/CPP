/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:25:41 by jlopez-f          #+#    #+#             */
/*   Updated: 2024/08/21 01:33:32 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cfloat>
#include <cmath>
#include <iomanip>

std::map<std::string, double>	BitcoinExchange::_database;
const std::string				BitcoinExchange::_database_name = "./data.csv";
const std::string				BitcoinExchange::_database_header = "date,exchange_rate";
const std::string				BitcoinExchange::_database_separator = ",";
const std::string				BitcoinExchange::_input_header = "date | value";
const std::string				BitcoinExchange::_input_separator = " | ";
const std::string				BitcoinExchange::_date_separator = "-";
const unsigned int				BitcoinExchange::_year_min = 1900;
const unsigned int				BitcoinExchange::_year_max = 2024;

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) { *this = other; }

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other) { (void)other; return (*this); }

int				BitcoinExchange::calculateExchange(std::string const filename)
{
	if (!loadDatabase())
		return (-1);
	return (loadInputFile(filename));
}

bool			BitcoinExchange::loadDatabase(void)
{
	std::ifstream	database_file;
	std::string		line, date, valuestr;
	std::size_t		pos;
	double			exchange_val;

	_database.clear();
	database_file.open(_database_name.c_str());
	if (!database_file)
		return (printerror("could not open database file."));
	while (std::getline(database_file, line))
	{
		if (line.empty() || line == _database_header)
			continue ;
		pos = line.find(_database_separator);
		if (pos == std::string::npos)
			return (printerror("invalid pair date-exchange rate in database file."));
		date = line.substr(0, pos);
		if (!parsedate(date))
			return (printerror("invalid date in database file."));
		valuestr = line.substr(pos + _database_separator.length(), std::string::npos);
		if (!parsedouble(valuestr, exchange_val))
			return (printerror("invalid exchange rate in database file."));
		if (_database.insert(std::make_pair(date, exchange_val)).second == false)
			return (printerror("duplicate date in database file."));
	}
	return (true);
}

bool			BitcoinExchange::loadInputFile(std::string const filename)
{
	std::ifstream	input_file;
	std::string		line, date, fulldate, valuestr;
	std::size_t		pos;
	double			value;

	input_file.open(filename.c_str());
	if (!input_file)
		return (printerror("could not open input file."));
	while (std::getline(input_file, line))
	{
		if (line.empty() || line == _input_header)
			continue ;
		pos = line.find(_input_separator);
		if (pos == std::string::npos)
		{
			printerror("bad input => " + line);
			continue ;
		}
		date = line.substr(0, pos);
		fulldate = date;
		if (!parsedate(date))
		{
			printerror("bad input. Invalid date.");
			continue ;
		}
		valuestr = line.substr(pos + _input_separator.length(), std::string::npos);
		if (!parsedouble(valuestr, value))
		{
			if (!valuestr.empty() && valuestr[0] == '-')
				printerror("not a positive number.");
			else
				printerror("bad input. Invalid value.");
			continue ;
		}
		if (value > 1000)
		{
			printerror("too large a number.");
			continue ;
		}
		printRealValue(date, fulldate, value);
	}
	return (true);
}

void			BitcoinExchange::printRealValue(std::string const date, std::string const fulldate, double value)
{
	std::map<std::string, double>::iterator	it;

	it = _database.lower_bound(date);
	if (it != _database.begin() && !(it != _database.end() && it->first == date))
		it--;
	std::cout << fulldate << " => " << value << " = " << std::fixed << std::setprecision(2) << value * it->second << std::endl;
}

bool			BitcoinExchange::parsedate(std::string &date)
{
	std::string	year, month, day;
	std::size_t	posyear, posmonth;
	
	if (date.empty())
		return (false);
	posyear = date.find(_date_separator);
	if (posyear == std::string::npos)
			return (false);
	year = date.substr(0, posyear);
	posmonth = date.find(_date_separator, posyear + 1);
	if (posmonth == std::string::npos)
			return (false);
	month = date.substr(posyear + 1, posmonth - posyear - 1);
	day = date.substr(posmonth + 1, std::string::npos);
	if (!isvalid_date(year, month, day))
			return (false);
	date = year + month + day;
	return (true);
}

bool			BitcoinExchange::parsedouble(std::string const num, double &doublenum)
{
	char	*endpos;

	if (!isvalid_double(num))
		return (false);
	doublenum = strtod(num.c_str(), &endpos);
	if (doublenum == HUGE_VAL || endpos != &(*num.end()) || doublenum < 0 ||\
		(doublenum > 0 && (doublenum > FLT_MAX || doublenum < FLT_MIN)))
		return (false);
	return (true);
}

bool			BitcoinExchange::isvalid_date(std::string const year, std::string const month, std::string const day)
{
	unsigned long		yearnum, monthnum, daynum;
	unsigned long		days_permonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	std::ostringstream	maxyear_size;

	maxyear_size << _year_max;
	if (!isvalid_int(year, maxyear_size.str().length()) || !isvalid_int(month, 2) || !isvalid_int(day, 2))
		return (false);
	yearnum = strtoul(year.c_str(), NULL, 10);
	monthnum = strtoul(month.c_str(), NULL, 10);
	daynum = strtoul(day.c_str(), NULL, 10);
	if (yearnum < _year_min || yearnum > _year_max || monthnum <= 0 || monthnum > 12)
		return (false);
	if (yearnum % 4 == 0 && (yearnum % 100 != 0 || yearnum % 400 == 0))
		days_permonth[1]++;
	if (daynum <= 0 || daynum > days_permonth[monthnum - 1])
		return (false);
	return (true);
}

bool			BitcoinExchange::isvalid_int(std::string const num, size_t max_size)
{
	if (num.empty() || num.length() > max_size)
		return (false);
	for (std::string::const_iterator it = num.begin(); it != num.end(); it++)
	{
		if (!isdigit(*it))
			return (false);
	}
	return (true);
}

bool			BitcoinExchange::isvalid_double(std::string const num)
{
	bool	dot = false;

	if (num.empty())
		return (false);
	for (std::string::const_iterator it = num.begin(); it != num.end(); it++)
	{
		if (*it == '.')
		{
			if (!dot)
				dot = true;
			else
				return (false);
		}
		else if (!isdigit(*it))
			return (false);
	}
	return (true);
}

bool			BitcoinExchange::printerror(std::string const err)
{
	std::cerr << "Error: " << err << std::endl;
	return (false);
}
