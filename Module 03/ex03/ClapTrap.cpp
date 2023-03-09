/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:26:23 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/06 16:12:30 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("ClapTrap"), _maxhp(10), _maxep(10),
_hitpoints(_maxhp), _energypoints(_maxep), _attackdamage(0)
{
	std::cout << "Allow me to introduce myself. I am a CL4P-TP steward robot, ";
	std::cout << "but my friends call me " << _name << std::endl;
}

ClapTrap::ClapTrap(std::string const name) : _name(name), _maxhp(10), _maxep(10),
_hitpoints(_maxhp), _energypoints(_maxep), _attackdamage(0)
{
	if (_name.empty())
		_name = "ClapTrap";
	std::cout << "Allow me to introduce myself. I am a CL4P-TP steward robot, ";
	std::cout << "but my friends call me " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "Copy booting sequence complete. Hello! I am your new ";
	std::cout << "steward bot. Designation: " << _name << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "I'll die the way I lived: annoying!" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
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

void	ClapTrap::attack(std::string const &target)
{
	std::cout << "I am Fire, I am Death! (";
	std::cout << _name << " attacks " << target << " causing ";
	std::cout << _attackdamage << " points of damage!)" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitpoints < amount)
		_hitpoints = 0;
	else
		_hitpoints -= amount;
	std::cout << "Gosh. This party is worse than stairs (";
	std::cout << _name << " receives " << amount << " of damage. ";
	std::cout << _hitpoints << " hitpoints left!)" << std::endl;
	if (_hitpoints == 0)
		std::cout << "I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitpoints + amount > _maxhp)
		_hitpoints = _maxhp;
	else
		_hitpoints += amount;
	std::cout << "I love you. What? Who said that? I didn't say anything. (";
	std::cout << _name << " was repaired " << amount << " hitpoints. ";
	std::cout << _hitpoints << " hitpoints left!)" << std::endl;
}

std::string	ClapTrap::getName(void) const
{
	return (_name);
}

int	ClapTrap::getHitpoints(void) const
{
	return (_hitpoints);
}

int	ClapTrap::getEnergyPoints(void) const
{
	return (_energypoints);
}

int	ClapTrap::getAttackDamage(void) const
{
	return (_attackdamage);
}

std::ostream	&operator<<(std::ostream &out, const ClapTrap &claptrap)
{
	std::cout << std::endl << "-------------------------------" << std::endl <<
		"ClapTrap name: " << claptrap.getName() << std::endl <<
		"Hitpoints: " << claptrap.getHitpoints() << std::endl <<
		"Energy Points: " << claptrap.getEnergyPoints() << std::endl <<
		"Attack damage: " << claptrap.getAttackDamage() << std::endl <<
		"-------------------------------" << std::endl;
	return (out);
}
