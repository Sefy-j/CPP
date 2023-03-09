/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:34:48 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/09 19:34:50 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassCat.hpp"

Cat::Cat(void) : Animal("cat"), _brain(new Brain)
{
	std::cout << "Hello human! I'm a cat, and I am ";
	std::cout << "a superior specie." << std::endl;
}

Cat::Cat(const Cat &other) : _brain(new Brain(*other.getBrain()))
{
	_type = other._type;
	std::cout << "This is weird...cats can't replicate, but here I am...";
	std::cout << "a replicated " << _type << ". Seems fun to me though!!" << std::endl;
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << "Do not let cats die :(" << std::endl;
}

Cat	&Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		_type = other._type;
		_brain = other.getBrain();
	}
	return (*this);
}

Brain	*Cat::getBrain(void) const
{
	return (_brain);
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat starts meowing: Miau miau!!" << std::endl;
}
