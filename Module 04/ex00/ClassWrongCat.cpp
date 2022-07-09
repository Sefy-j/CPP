/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassWrongCat.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:34:13 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/09 19:34:14 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassWrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("wrong cat")
{
	std::cout << "Hello human! I'm a wrong cat. ";
	std::cout << "I am human best friend!! " << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
	*this = other;
	std::cout << "This is weird...wrong cats can't replicate, but here I am...";
	std::cout << "a replicated " << _type << ". Seems fun to me though!!" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Do not let wrong cats die :(" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Wrong cat starts barking: Guau guau!!" << std::endl;
}
