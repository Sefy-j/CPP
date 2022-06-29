/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 08:37:58 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/06/29 14:34:49 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie	*ptrZ;

	ptrZ = newZombie("PtrZ");
	ptrZ->announce();
	delete ptrZ;
	ptrZ = new Zombie;
	ptrZ->announce();
	delete ptrZ;
	randomChump("Zombheap");
	Zombie Zombheap;
	Zombheap.announce();
	Zombheap.setname("NamedZ");
	Zombheap.announce();
}