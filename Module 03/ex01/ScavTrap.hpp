/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:12:45 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/04 19:28:00 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:

		ScavTrap(void);
		ScavTrap(std::string const name);
		ScavTrap(const ScavTrap &other);
		~ScavTrap(void);

		ScavTrap	&operator=(const ScavTrap &other);

		std::string	getGuardmode(void) const;

		void	attack(std::string const &target);
		void	guardGate(void);

	private:
	
		bool	_guardmode;
};

std::ostream	&operator<<(std::ostream &out, const ScavTrap &scavtrap);

#endif
