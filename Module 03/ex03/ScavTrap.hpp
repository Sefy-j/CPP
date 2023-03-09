/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:12:45 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/06 12:33:52 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:

		ScavTrap(void);
		ScavTrap(std::string const name);
		ScavTrap(const ScavTrap &other);
		virtual	~ScavTrap(void);

		ScavTrap	&operator=(const ScavTrap &other);

		std::string	getGuardmode(void) const;

		void	attack(std::string const &target);
		void	guardGate(void);

	protected:
	
		bool	_guardmode;
};

std::ostream	&operator<<(std::ostream &out, const ScavTrap &scavtrap);

#endif
