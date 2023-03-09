/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 08:37:58 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/04 12:31:34 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie	*ptrZ;

	ptrZ = newZombie("PtrZ");
	ptrZ->announce();
	delete ptrZ;
	ptrZ = new Zombie;
	ptrZ->announce();
	delete ptrZ;
	randomChump("Zombstack");
	Zombie Zombstack;
	Zombstack.announce();
	Zombstack.setname("NamedZ");
	Zombstack.announce();
}
