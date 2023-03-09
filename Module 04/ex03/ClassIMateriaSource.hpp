/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassIMateriaSource.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:37:01 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/09 19:37:01 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSIMATERIASOURCE_HPP
# define CLASSIMATERIASOURCE_HPP

#include "ClassAMateria.hpp"

class IMateriaSource
{
	public:
		virtual	~IMateriaSource(void) {}

		virtual void		learnMateria(AMateria*) = 0;
		virtual AMateria*	createMateria(std::string const & type) = 0;
};

#endif
