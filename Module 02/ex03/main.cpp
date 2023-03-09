/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 08:37:58 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/04 14:02:05 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

std::string	printresult(bool evaluation)
{
	std::string	result;

	if (evaluation == 1)
		result = " is inside the triangle";
	else
		result = " is outside the triangle";
	return (result);
}

int	main(void)
{
	Point		a(0, 0);
	Point		b(5, 0);
	Point		c(0, 5);
	Point		p(0,0);
	std::string	result;

	std::cout << "Point (" << p.get_x() << ", " << p.get_y() << ")";
	std::cout << printresult(bsp(a, b, c, p)) << std::endl;
	p = Point(2, 0);
	std::cout << "Point (" << p.get_x() << ", " << p.get_y() << ")";
	std::cout << printresult(bsp(a, b, c, p)) << std::endl;
	p = Point(1, 1);
	std::cout << "Point (" << p.get_x() << ", " << p.get_y() << ")";
	std::cout << printresult(bsp(a, b, c, p)) << std::endl;
	p = Point(1, -1);
	std::cout << "Point (" << p.get_x() << ", " << p.get_y() << ")";
	std::cout << printresult(bsp(a, b, c, p)) << std::endl;
	p = Point(-1, 1);
	std::cout << "Point (" << p.get_x() << ", " << p.get_y() << ")";
	std::cout << printresult(bsp(a, b, c, p)) << std::endl;
	p = Point(5, 3);
	std::cout << "Point (" << p.get_x() << ", " << p.get_y() << ")";
	std::cout << printresult(bsp(a, b, c, p)) << std::endl;
	return (0);
}
