/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:12:45 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/06 12:33:19 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	public:

		ClapTrap(void);
		ClapTrap(std::string const name);
		ClapTrap(const ClapTrap &other);
		virtual	~ClapTrap(void);

		ClapTrap	&operator=(const ClapTrap &other);

		std::string	getName(void) const;
		int			getHitpoints(void) const;
		int			getEnergyPoints(void) const;
		int			getAttackDamage(void) const;

		void	attack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	protected:

		std::string		_name;
		unsigned int	_maxhp;
		unsigned int	_maxep;
		unsigned int	_hitpoints;
		unsigned int	_energypoints;
		unsigned int	_attackdamage;

};

std::ostream	&operator<<(std::ostream &out, const ClapTrap &claptrap);

#endif