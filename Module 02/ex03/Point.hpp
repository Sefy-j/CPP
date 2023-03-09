/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:12:45 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/04 12:14:07 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:

		Point(void);
		Point(const float x, const float y);
		Point(const Point &other);
		~Point(void);

		Point	&operator=(const Point &other);

		Fixed	get_x(void) const;
		Fixed	get_y(void) const;

	private:

		Fixed	_x;
		Fixed	_y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

enum {
	X = 0,
	Y = 1
};

#endif