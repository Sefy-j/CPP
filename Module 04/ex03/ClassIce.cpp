/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassIce.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:36:49 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/09 19:36:50 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassIce.hpp"

Ice::Ice(void) : AMateria("ice")
{
	//std::cout << "A new Ice materia!! Perfect to freeze that ";
	//std::cout << "Sephiroth" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria("ice")
{
	(void)other;
	//std::cout << "Ice materia was mastered!! A duplicate has appear!!" << std::endl;
}

Ice::~Ice(void)
{
	//std::cout << "No more ice for me...not cool" << std::endl;
}

Ice	&Ice::operator=(const Ice &other)
{
	(void)other;
	return (*this);
}

const std::string	&Ice::getType(void) const
{
	return (_type);
}

AMateria* Ice::clone(void) const
{
	return (new Ice);
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
