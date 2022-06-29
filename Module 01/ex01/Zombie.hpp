/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:12:45 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/06/29 19:23:26 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	public:

		Zombie(void);
		Zombie(std::string zname);
		~Zombie(void);
		
		void	announce(void) const;
		void	setname(std::string zname);

	private:

		static int	_total;

		std::string	_name;
		int			_i;
};

Zombie* zombieHorde(int N, std::string name);

#endif