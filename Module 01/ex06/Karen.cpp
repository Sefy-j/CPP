/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:26:23 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/06/30 16:10:36 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen(void){}

Karen::~Karen(void){}

void	Karen::complain(std::string level)
{
	int			i;
	std::string	complain[4];

	complain[0] = "DEBUG";
	complain[1] = "INFO";
	complain[2] = "WARNING";
	complain[3] = "ERROR";
	for (i = 0; i < 4; i++)
	{
		if (!complain[i].compare(level))
			break ;
	}
	switch(i)
	{
		case 0: debug();
		case 1: info();
		case 2: warning();
		case 3: error();
				break ;
		default: std::cout << "[ Probably complaining about insignificant ";
				std::cout << "problems ]" << std::endl;
	}
}

void	Karen::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love to get extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger. ";
	std::cout << "I just love it!" << std::endl << std::endl;
}

void	Karen::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. ";
	std::cout << "You don't put enough! If you did I would not have to ask for it!";
	std::cout << std::endl << std::endl;
}

void	Karen::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I've been coming here for years and you just started ";
	std::cout << "working here last month..." << std::endl << std::endl;
}

void	Karen::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now...";
	std::cout << std::endl << std::endl;
}
