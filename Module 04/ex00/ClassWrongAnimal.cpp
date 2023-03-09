/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassWrongAnimal.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:34:05 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/09 19:34:06 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassWrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("unknown wrong animal")
{
	std::cout << "Hello human! I'm an unknown wrong animal Am I cute? Am I dangerous? ";
	std::cout << "I just wanna be your friend!! " << std::endl;
}

WrongAnimal::WrongAnimal(std::string const type) : _type(type)
{
	if (_type.empty())
		_type = "unknown wrong animal";
	std::cout << "Hello human! I'm a " << _type << " Am I cute? Am I dangerous? ";
	std::cout << "I just wanna be your friend!! " << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	*this = other;
	std::cout << "This is weird...wrong animals can't replicate, but here I am...";
	std::cout << "a replicated " << _type << ". Seems fun to me though!!" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Do not let wrong animals die :(" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << _type << " makes a wrong sound" << std::endl;
}

const std::string	WrongAnimal::getType(void) const
{
	return (_type);
}
