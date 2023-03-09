/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:12:00 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/17 23:03:13 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.hpp"

void	conversion(std::string str)
{
	if (str.empty())
		std::cout << "Error. Empty argument" << std::endl;
	else if (checkchar(str))
		charconversion(str[0]);
	else if (checkint(str))
		intconversion(str);
	else if (checkfloat(str))
		floatconversion(str);
	else if (checkdouble(str))
		doubleconversion(str);
	else
		std::cout << "Error. Non conversion possible" << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error. Wrong number of arguments" << std::endl;
		return (1);
	}
	conversion(argv[1]);
	return (0);
}