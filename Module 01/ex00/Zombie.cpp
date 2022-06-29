/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:26:23 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/06/29 19:22:44 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void){}

Zombie::Zombie(std::string zname) : _name(zname) {}

Zombie::~Zombie(void)
{
	if (_name.empty())
		std::cout << "Unnamed zombie" << ": No more brainzz for me..." << std::endl;
	else
		std::cout << _name << ": No more brainzz for me..." << std::endl;
}

void	Zombie::setname(std::string zname)
{
	_name = zname;
}

void	Zombie::announce(void) const
{
	if (_name.empty())
		std::cout << "Unnamed zombie" << ": BraiiiiiiinnnzzzZ..." << std::endl;
	else
		std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
