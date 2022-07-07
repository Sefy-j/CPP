/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:26:23 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/04 18:54:53 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassCure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	//std::cout << "A new cure materia!! I really needed it ";
	//std::cout << "for my wounds" << std::endl;
}

Cure::Cure(const Cure &other)
{
	//std::cout << "Cure materia was mastered!! A duplicate has appear!!" << std::endl;
}

Cure::~Cure(void)
{
	//std::cout << "Can anyone heal a cure materia? It got destroyed..." << std::endl;
}

Cure	&Cure::operator=(const Cure &other)
{
	return (*this);
}

const std::string	&Cure::getType(void) const
{
	return (_type);
}

AMateria* Cure::clone(void) const
{
	return (new Cure);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
