/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:26:23 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/04 18:54:53 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassCharacter.hpp"

Character::Character(void) : ICharacter(), _name("unknown")
{
	int	i;

	for (i = 0; i < 4; i++)
		_inventory[i] = NULL;
	//std::cout << "A new unknown character joins your party!!" << std::endl;
}

Character::Character(std::string const name) : ICharacter(), _name(name)
{
	int	i;

	if (_name.empty())
		_name = "unknown";
	for (i = 0; i < 4; i++)
		_inventory[i] = NULL;
	//std::cout << "A new " << _type << " character joins ";
	//std::cout << "your party!!" << std::endl;
}

Character::Character(const Character &other)
{
	*this = other;
	//std::cout << "Did I just clone myself?? I'm " << _name;
	//std::cout << " , but am I the original one or the copy?" << std::endl;
}

Character::~Character(void)
{
	int	i;

	for (i = 0; i < 4; i++)
		delete _inventory[i];
	//std::cout << _name << " died in terrible pain..." << std::endl;
}

Character	&Character::operator=(const Character &other)
{
	int	i;
	AMateria	*temp[4];

	if (this != &other)
	{
		_name = other._name;
		for (i = 0; i < 4; i++)
			temp[i] = *temp[i].clone(other.getMateria(i));
		for (i = 0; i < 4; i++)
		{
			delete _inventory[i];
			_inventory[i] = temp[i];
		}
	}
	return (*this);
}

const std::string	&Character::getName(void) const
{
	return (_name);
}

AMateria	*Character::getMateria(int n) const
{
	return (_inventory[n]);
}

void	Character::equip(AMateria *m) const
{
	int	i;

	while (i < 4 && _inventory[i])
		i++;
	if (i == 4)
	{
		std::cout << "Inventory full. Please unequip a materia first" << std::endl; 
		return ;	
	}
	*_inventory[i] = *m;
}

void	Character::unequip(int idx)
{

}

void	Character::use(int idx, ICharacter &target)
{

}
