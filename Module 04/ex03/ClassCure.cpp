/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassCure.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:36:42 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/09 19:36:43 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassCure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	//std::cout << "A new cure materia!! I really needed it ";
	//std::cout << "for my wounds" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria("cure")
{
	(void)other;
	//std::cout << "Cure materia was mastered!! A duplicate has appear!!" << std::endl;
}

Cure::~Cure(void)
{
	//std::cout << "Can anyone heal a cure materia? It got destroyed..." << std::endl;
}

Cure	&Cure::operator=(const Cure &other)
{
	(void)other;
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
