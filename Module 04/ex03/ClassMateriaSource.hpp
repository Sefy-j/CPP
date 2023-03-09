/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassMateriaSource.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:37:13 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/10 14:11:36 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSMATERIASOURCE_HPP
# define CLASSMATERIASOURCE_HPP

#include "ClassIMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	public:

		MateriaSource(void);
		MateriaSource(const MateriaSource &other);
		~MateriaSource(void);

		MateriaSource	&operator=(const MateriaSource &other);

		AMateria	*getMateriaSource(int n) const;

		void		learnMateria(AMateria *m);
		AMateria*	createMateria(std::string const &type);

	protected:

		AMateria	*_msources[4];
};

#endif
