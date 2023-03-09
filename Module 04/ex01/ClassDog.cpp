/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:34:58 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/09 19:34:59 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassDog.hpp"

Dog::Dog(void) : Animal("dog"), _brain(new Brain)
{
	std::cout << "Hello human! I'm a dog. ";
	std::cout << "I am human best friend!! " << std::endl;
}

Dog::Dog(const Dog &other) : _brain(new Brain(*other.getBrain()))
{
	_type = other._type;
	std::cout << "This is weird...dogs can't replicate, but here I am...";
	std::cout << "a replicated " << _type << ". Seems fun to me though!!" << std::endl;
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Do not let dogs die :(" << std::endl;
}

Dog	&Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		_type = other._type;
		_brain = other.getBrain();
	}
	return (*this);
}

Brain	*Dog::getBrain(void) const
{
	return (_brain);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog starts barking: Guau guau!!" << std::endl;
}
