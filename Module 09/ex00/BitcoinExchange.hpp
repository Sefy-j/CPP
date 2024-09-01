/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:20:57 by jlopez-f          #+#    #+#             */
/*   Updated: 2024/08/20 00:52:13 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange
{
	public:

		static int		calculateExchange(std::string const filename);

	private:

		static std::map<std::string, double>	_database;
		static const std::string				_database_name;
		static const std::string				_database_header;
		static const std::string				_database_separator;
		static const std::string				_input_header;
		static const std::string				_input_separator;
		static const std::string				_date_separator;
		static const unsigned int				_year_min;
		static const unsigned int				_year_max;

		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange(void);

		BitcoinExchange	&operator=(const BitcoinExchange &other);

		static bool		loadDatabase(void);
		static bool		loadInputFile(std::string const filename);
		
		static void		printRealValue(std::string const date, std::string const fulldate, double value);

		static bool		parsedate(std::string &date);
		static bool		parsedouble(std::string const num, double &doublenum);
		static bool		isvalid_date(std::string const year, std::string const month, std::string const day);
		static bool		isvalid_int(std::string const str, size_t max_size);
		static bool		isvalid_double(std::string const str);

		static bool		printerror(std::string const err);
};

#endif
