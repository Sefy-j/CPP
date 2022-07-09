/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassAMateria.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:12:45 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/07 13:05:33 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSAMATERIA_HPP
# define CLASSAMATERIA_HPP

#include <iostream>
#include "ClassICharacter.hpp"

class ICharacter;

class AMateria
{
	public:

		AMateria(void);
		AMateria(std::string const type);
		AMateria(const AMateria &other);
		virtual	~AMateria(void);

		AMateria	&operator=(const AMateria &other);

		std::string const	&getType(void) const;

		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target);

	protected:

		std::string		_type;
};

#endif
