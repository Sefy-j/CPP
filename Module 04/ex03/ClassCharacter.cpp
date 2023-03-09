/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassCharacter.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:36:17 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/10 14:52:34 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassCharacter.hpp"

Character::Character(void) : ICharacter(), _name("unknown"),
_inventory()
{
	//std::cout << "A new unknown character joins your party!!" << std::endl;
}

Character::Character(std::string const name) : ICharacter(), _name(name),
_inventory()
{
	if (_name.empty())
		_name = "unknown";
	//std::cout << "A new " << _name << " character joins ";
	//std::cout << "your party!!" << std::endl;
}

Character::Character(const Character &other) : ICharacter(),
_inventory()
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
		for (i = 0; i < 4; i++)
		{
			if (other.getMateria(i))
				temp[i] = other.getMateria(i)->clone();
			else
				temp[i] = NULL;
		}
		for (i = 0; i < 4; i++)
		{
			delete _inventory[i];
			_inventory[i] = temp[i];
		}
		_name = other._name;
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

void	Character::equip(AMateria *m)
{
	int	i;

	i = 0;
	while (i < 4 && _inventory[i])
		i++;
	if (i == 4)
	{
		std::cout << "Inventory full. Please unequip a materia first" << std::endl;
		return ;	
	}
	//std::cout << "Equiped materia " << m->getType() << " in slot " << i << std::endl;
	_inventory[i] = m;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
	{
		std::cout << _inventory[idx]->getType() << " materia unequipped" << std::endl; 
		_inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);
	else
		std::cout << "No materia equipped in that slot" << std::endl; 

}
