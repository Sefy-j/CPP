/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 23:01:50 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/17 23:04:23 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.hpp"

bool	checkdouble(std::string str)
{
	double	d;
	char	*end;

	if (str == "-inf" || str == "+inf" || str == "nan")
		return (true);
	errno = 0;
	d = strtod(str.c_str(), &end);
	if (*end || errno || str[0] == 'i')
		return (false);
	return (true);
}

bool	checkfloat(std::string str)
{
	double	f;
	char	*end;

	if (str == "-inff" || str == "+inff" || str == "nanf")
		return (true);
	errno = 0;
	f = strtod(str.c_str(), &end);
	if (*end != 'f' || errno)
		return (false);
	if ((f > 0 && (f > FLT_MAX || f < FLT_MIN)) || (f < 0 && (-f > FLT_MAX || -f < FLT_MIN)))
		return (false);
	return (true);
}

bool	checkint(std::string str)
{
	long int	n;
	char		*end;

	n = strtol(str.c_str(), &end, 0);
	if (*end || n > INT_MAX || n < INT_MIN)
		return (false);
	return (true);
}

bool	checkchar(std::string str)
{
	if (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]))
			return (true);
	return (false);
}