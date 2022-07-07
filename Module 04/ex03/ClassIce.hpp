/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassIce.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:12:45 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/07 10:40:56 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSICE_HPP
# define CLASSICE_HPP

#include "ClassAMateria.hpp"

class Ice: public AMateria
{
	public:

		Ice(void);
		Ice(const Ice &other);
		~Ice(void);

		Ice	&operator=(const Ice &other);

		std::string const	&getType(void) const;

		AMateria	*clone(void) const;
		void		use(ICharacter &target);
};

#endif
