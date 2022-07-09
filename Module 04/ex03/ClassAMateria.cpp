/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassAMateria.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:26:23 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/09 19:52:55 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassAMateria.hpp"

AMateria::AMateria(void) : _type("unknown")
{
	//std::cout << "An unknown materia to equip in my gear? ";
	//std::cout << "What could go wrong?" << std::endl;
}

AMateria::AMateria(std::string const type) : _type(type)
{
	if (_type.empty())
		_type = "unknown";
	//std::cout << "A new " << _type << " materia!! I can't wait ";
	//std::cout << "to use it in the next battle!!" << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	*this = other;
	//std::cout << "Welp, I haven't mastered this " << _type;
	//std::cout << "materia...where did it come from?" << std::endl;
}

AMateria::~AMateria(void)
{
	//std::cout << "My " << _type << "materia shattered!!" << std::endl;
}

AMateria	&AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

const std::string	&AMateria::getType(void) const
{
	return (_type);
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "* uses his " << _type << "materia against " << target.getName() << " *" << std::endl;
}
