/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:26:23 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/04 19:44:01 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	_maxhp = 100;
	_maxep = 100;
	_hitpoints = _maxhp;
	_energypoints = _maxep;
	_attackdamage = 30;
	std::cout << "Activating VaultHunter.EXE. " << _name;
	std::cout << " set to FragTrap mode" << std::endl;
}


FragTrap::FragTrap(std::string const name) : ClapTrap(name)
{
	_maxhp = 100;
	_maxep = 100;
	_hitpoints = _maxhp;
	_energypoints = _maxep;
	_attackdamage = 30;
	std::cout << "Activating VaultHunter.EXE. " << _name;
	std::cout << " set to FragTrap mode" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
{
	*this = other;
	std::cout << "Copy booting sequence complete. Hello! I am your new ";
	std::cout << "FragTrap bot. Designation: " << _name << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Deactivating VaultHunter.EXE. ";
	std::cout << "FragTrap mode unset" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		_name = other._name;
		_maxhp = other._maxhp;
		_maxep = other._maxep;
		_hitpoints = other._hitpoints;
		_energypoints = other._energypoints;
		_attackdamage = other._attackdamage;
	}
	return (*this);
}

void	FragTrap::attack(std::string const &target)
{
	std::cout << "I am Fire, I am Death! And I'll Frag you!! (";
	std::cout << _name << " attacks " << target << " causing ";
	std::cout << _attackdamage << " points of damage!)" << std::endl;
}

void FragTrap::highFivesGuys()
{

	std::cout << "If that doesn't deserve a high-five, NOTHING does! (FragTrap ";
	std::cout << _name << " raises his robot hand waiting for you)" << std::endl;
}

std::ostream	&operator<<(std::ostream &out, const FragTrap &fragtrap)
{
	std::cout << std::endl << "-------------------------------" << std::endl <<
		"FragTrap name: " << fragtrap.getName() << std::endl <<
		"Hitpoints: " << fragtrap.getHitpoints() << std::endl <<
		"Energy Points: " << fragtrap.getEnergyPoints() << std::endl <<
		"Attack damage: " << fragtrap.getAttackDamage() << std::endl <<
		"-------------------------------" << std::endl;
	return (out);
}
