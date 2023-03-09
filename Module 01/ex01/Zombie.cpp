/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:26:23 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/06/29 19:21:22 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int Zombie::_total = 0;

Zombie::Zombie(void) : _i(++_total) {}

Zombie::Zombie(std::string zname) : _name(zname), _i(++_total) {}

Zombie::~Zombie(void)
{

	if (_name.empty())
		std::cout << "Unnamed zombie " << _i << ": No more brainzz for me..." << std::endl;
	else
		std::cout << _name << " " << _i << ": No more brainzz for me..." << std::endl;
	_total--;
}

void	Zombie::setname(std::string zname)
{
	_name = zname;
}

void	Zombie::announce(void) const
{
	if (_name.empty())
		std::cout << "Unnamed zombie " << _i << ": BraiiiiiiinnnzzzZ..." << std::endl;
	else
		std::cout << _name << " " << _i << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
