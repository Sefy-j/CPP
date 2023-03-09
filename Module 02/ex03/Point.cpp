/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:26:23 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/04 16:43:32 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(Fixed()), _y(Fixed())
{
	//std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y))
{
	//std::cout << "Float constructor called" << std::endl;
}

Point::Point(const Point &other)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Point::~Point(void)
{
	//std::cout << "Destructor called" << std::endl;
}

Point	&Point::operator=(const Point &other)
{
	//std::cout << "Assignation operator called" << std::endl;
	if (this != &other)
	{
		_x = other._x;
		_y = other._y;
	}
	return (*this);
}

Fixed	Point::get_x(void) const
{
	return (_x);
}

Fixed	Point::get_y(void) const
{
	return (_y);
}
