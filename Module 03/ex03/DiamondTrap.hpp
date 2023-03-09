/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:12:45 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/05 00:01:26 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap :  public ScavTrap, public FragTrap
{
	public:

		DiamondTrap(void);
		DiamondTrap(std::string const name);
		DiamondTrap(const DiamondTrap &other);
		~DiamondTrap(void);

		DiamondTrap	&operator=(const DiamondTrap &other);

		std::string	getClapName(void) const;

		using	ScavTrap::attack;		
		void	whoAmI(void) const;
	
	private:

		std::string	_name;
};

std::ostream	&operator<<(std::ostream &out, const DiamondTrap &diamondtrap);

#endif
