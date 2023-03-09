/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:34:25 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/09 19:34:26 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassAnimal.hpp"

Animal::Animal(void) : _type("unknown animal")
{
	std::cout << "Hello human! I'm an unknown animal. Am I cute? Am I dangerous? ";
	std::cout << "I just wanna be your friend!! " << std::endl;
}

Animal::Animal(std::string const type) : _type(type)
{
	if (_type.empty())
		_type = "unknown animal";
	std::cout << "Hello human! I'm a " << _type << ". Am I cute? Am I dangerous? ";
	std::cout << "I just wanna be your friend!! " << std::endl;
}

Animal::Animal(const Animal &other)
{
	*this = other;
	std::cout << "This is weird...animals can't replicate, but here I am...";
	std::cout << "a replicated " << _type << ". Seems fun to me though!!" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Do not let animals die :(" << std::endl;
}

Animal	&Animal::operator=(const Animal &other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << _type << " makes a weird sound" << std::endl;
}

const std::string	Animal::getType(void) const
{
	return (_type);
}
