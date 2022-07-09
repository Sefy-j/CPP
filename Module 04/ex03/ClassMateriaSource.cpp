/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassMateriaSource.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:37:06 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/09 19:37:07 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassMateriaSource.hpp"

MateriaSource::MateriaSource(void) : IMateriaSource(), _msources()
{
	//std::cout << "We got a new Materia Source, now we can learn some!!" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	*this = other;
	//std::cout << "A cloned Materia Source? Could we really master a " << _name;
	//std::cout << "source?" << std::endl;
}

MateriaSource::~MateriaSource(void)
{
	int	i;

	for (i = 0; i < 4; i++)
		delete _msources[i];
	//std::cout << _name << " died in terrible pain..." << std::endl;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &other)
{
	int	i;
	AMateria	*temp[4];

	if (this != &other)
	{
		for (i = 0; i < 4; i++)
			temp[i] = other.getMateriaSource(i)->clone();
		for (i = 0; i < 4; i++)
		{
			delete _msources[i];
			_msources[i] = temp[i];
		}
	}
	return (*this);
}

AMateria	*MateriaSource::getMateriaSource(int n) const
{
	return (_msources[n]);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	int	i;

	i = 0;
	while (i < 4 && _msources[i])
		i++;
	if (i == 4)
	{
		std::cout << "Materia source full" << std::endl; 
		return ;	
	}
	_msources[i] = m;
}

AMateria*	MateriaSource::createMateria(std::string const &type)
{
	int	i;

	for (i = 0; i < 4; i++)
	{
		if (type.compare(_msources[i]->getType()))
			return (_msources[i]->clone());
	}
	return (NULL);
}
