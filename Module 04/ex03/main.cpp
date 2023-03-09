/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 08:37:58 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/10 14:47:16 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassAMateria.hpp"
#include "ClassMateriaSource.hpp"
#include "ClassCure.hpp"
#include "ClassIce.hpp"
#include "ClassCharacter.hpp"

int	main(void)
{
	{
		IMateriaSource*	src;
		AMateria		*tmp;
		ICharacter		*cloud;
		ICharacter		*sefy;

		src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		tmp = new Cure();
		src->learnMateria(tmp);
		src->learnMateria(tmp);
		std::cout << std::endl;

		cloud = new Character("Cloud");
		tmp = src->createMateria("ice");
		cloud->equip(tmp);
		tmp = src->createMateria("ice");
		cloud->equip(tmp);
		tmp = src->createMateria("cure");
		cloud->equip(tmp);
		tmp = src->createMateria("cure");
		cloud->equip(tmp);
		cloud->equip(tmp);
		cloud->unequip(3);
		cloud->equip(tmp);
		std::cout << std::endl;

		sefy = new Character("Sephiroth");
		cloud->use(0, *sefy);
		cloud->use(2, *sefy);

		delete cloud;
		delete sefy;
		delete src;
	}
	std::cout << std::endl << "////////////////////" << std::endl << std::endl;
	{ 
		Character	*zack;
		Character	*cloud;
		ICharacter	*sefy;

		zack = new Character("Zack");
		zack->equip(new Ice());
		zack->equip(new Cure());
		cloud = new Character(*zack);
		delete zack;
		sefy = new Character("Sephiroth");
		cloud->use(0, *sefy);
		cloud->use(1, *sefy);
		delete cloud;
		std::cout << std::endl;
		
		zack = new Character("Zack");
		zack->equip(new Cure());
		zack->equip(new Ice());
		cloud = new Character("Cloud");
		*cloud = *zack;
		delete zack;
		cloud->use(0, *sefy);
		cloud->use(1, *sefy);
		delete cloud;
		delete sefy;
	}
	std::cout << std::endl << "////////////////////" << std::endl << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
		return (0);
	}
}
