/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:06:28 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/04 14:03:18 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	pa[2] = {a.get_x(), a.get_y()};
	Fixed	pb[2] = {b.get_x(), b.get_y()};
	Fixed	pc[2] = {c.get_x(), c.get_y()};
	Fixed	p[2] = {point.get_x(), point.get_y()};
	float	area;
	float	s;
	float	t;

	area = 0.5 * (- pb[Y] * pc[X] + pa[Y] * (- pb[X] + pc[X]) + pa[X] * (pb[Y] - pc[Y]) + pb[X] * pc[Y]).toFloat();
	s = 1/(2 * area) * (pa[Y] * pc[X] - pa[X] * pc[Y] + (pc[Y] - pa[Y]) * p[X] + (pa[X] - pc[X]) * p[Y]).toFloat();
	t = 1/(2 * area) * (pa[X] * pb[Y] - pa[Y] * pb[X] + (pa[Y] - pb[Y]) * p[X] + (pb[X] - pa[X]) * p[Y]).toFloat();
	if ((s > 0 && t > 0 && 1 - s - t > 0))
		return (true);
	else
		return (false);
}
