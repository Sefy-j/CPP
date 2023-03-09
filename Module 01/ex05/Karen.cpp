/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:26:23 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/06/30 15:53:19 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen(void){}

Karen::~Karen(void){}

void	Karen::complain(std::string level)
{
	int			i;
	std::string	complain[4];

	ptrf[0] = &Karen::debug;
	ptrf[1] = &Karen::info;
	ptrf[2] = &Karen::warning;
	ptrf[3] = &Karen::error;
	complain[0] = "DEBUG";
	complain[1] = "INFO";
	complain[2] = "WARNING";
	complain[3] = "ERROR";
	for (i = 0; i < 4; i++)
	{
		if (!complain[i].compare(level))
			(this->*ptrf[i])();
	}
}

void	Karen::debug(void)
{
	std::cout << "I love to get extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger. ";
	std::cout << "I just love it!" << std::endl;
}

void	Karen::info(void)
{
	std::cout << "I cannot believe adding extra bacon cost more money. ";
	std::cout << "You don't put enough! If you did I would not have to ask for it!";
	std::cout << std::endl;
}

void	Karen::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I've been coming here for years and you just started ";
	std::cout << "working here last month..." << std::endl;
}

void	Karen::error(void)
{
	std::cout << "This is unacceptable, I want to speak to the manager now...";
	std::cout << std::endl;
}
