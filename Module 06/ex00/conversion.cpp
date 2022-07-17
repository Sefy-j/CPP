/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:25:41 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/17 23:01:56 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.hpp"

void	specialdouble(std::string str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << str << "f" << std::endl;
	std::cout << "double: " << str << std::endl;
}

void	specialfloat(std::string str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << str << std::endl;
	std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
}

void	doubleconversion(std::string str)
{
	double	d;

	if (str == "-inf" || str == "+inf" || str == "nan")
	{
		specialdouble(str);
		return ;
	}
	d = strtod(str.c_str(), 0);
	if (d > 255.0 || d < 0.0)
		std::cout << "char: impossible" << std::endl;
	else if (isprint(static_cast<int>(d)))
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (d > static_cast<double>(INT_MAX) || d < static_cast<double>(INT_MIN))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	if (static_cast<double>(static_cast<int>(d)) == d)
		std::cout << std::fixed << std::setprecision(1);
	if ((d > 0 && (d > FLT_MAX || d < FLT_MIN)) || (d < 0 && (-d > FLT_MAX || -d < FLT_MIN)))
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void	floatconversion(std::string str)
{
	float f;

	if (str == "-inff" || str == "+inff" || str == "nanf")
	{
		specialfloat(str);
		return ;
	}
	f = strtod(str.c_str(), 0);
	if (f > 255.0f || f < 0.0f)
		std::cout << "char: impossible" << std::endl;
	else if (isprint(static_cast<int>(f)))
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (f > static_cast<float>(INT_MAX) || f < static_cast<float>(INT_MIN))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	if (static_cast<float>(static_cast<int>(f)) == f)
		std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void	intconversion(std::string str)
{
	int	n;

	n = atoi(str.c_str());
	if (n > 255 || n < 0)
		std::cout << "char: impossible" << std::endl;
	else if (isprint(n))
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(n) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(n) << std::endl;
}

void	charconversion(char c)
{
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}