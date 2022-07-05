/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:26:23 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/04 23:59:42 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("ClapTrap_clap_name"),
ScavTrap(), FragTrap(), _name("ClapTrap")
{
	_maxep = 50;
	_energypoints = _maxep;
	std::cout << "Activating UltraVaultHunter.EXE. " << _name;
	std::cout << " set to DiamondTrap mode" << std::endl;
}


DiamondTrap::DiamondTrap(std::string const name) : ClapTrap(name + "_clap_name"),
ScavTrap(), FragTrap(), _name(name)
{
	_maxep = 50;
	_energypoints = _maxep;
	std::cout << "Activating UltraVaultHunter.EXE. " << _name;
	std::cout << " set to DiamondTrap mode" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	*this = other;
	std::cout << "Copy booting sequence complete. Hello! I am your new ";
	std::cout << "DiamondTrap bot. Designation: " << _name << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Deactivating UltraVaultHunter.EXE. ";
	std::cout << "Diamond mode unset" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		_name = other._name;
		ClapTrap::_name = other.ClapTrap::_name;
		_maxhp = other._maxhp;
		_maxep = other._maxep;
		_hitpoints = other._hitpoints;
		_energypoints = other._energypoints;
		_attackdamage = other._attackdamage;
		_guardmode = other._guardmode;
	}
	return (*this);
}

std::string	DiamondTrap::getClapName(void) const
{
	return (_name);
}

void	DiamondTrap::whoAmI(void) const
{
	std::cout << "Hi! My name is " << _name << " and my original name is ";
	std::cout << this->getName() << " and I am the best robot. Yeah, yeah, yeah, ";
	std::cout << "I am the best robot. Ooh, ooh, here we go!" << std::endl;
}

std::ostream	&operator<<(std::ostream &out, const DiamondTrap &diamondtrap)
{
	std::cout << std::endl << "-------------------------------" << std::endl <<
		"DiamondTrap name: " << diamondtrap.getClapName() << std::endl <<
		"DiamondTrap original name: " << diamondtrap.getName() << std::endl <<
		"Hitpoints: " << diamondtrap.getHitpoints() << std::endl <<
		"Energy Points: " << diamondtrap.getEnergyPoints() << std::endl <<
		"Attack damage: " << diamondtrap.getAttackDamage() << std::endl <<
		"Guardmode: " << diamondtrap.getGuardmode() << std::endl <<
		"-------------------------------" << std::endl;
	return (out);
}
