/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 22:59:09 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/20 11:40:54 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
# define CONVERSION_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cfloat>

bool	checkchar(std::string str);
bool	checkint(std::string str);
bool	checkfloat(std::string str);
bool	checkdouble(std::string str);
void	charconversion(char c);
void	intconversion(std::string str);
void	floatconversion(std::string str);
void	doubleconversion(std::string str);

#endif