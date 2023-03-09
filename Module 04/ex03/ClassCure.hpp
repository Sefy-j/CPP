/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassCure.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:12:45 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/07 10:40:56 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSCURE_HPP
# define CLASSCURE_HPP

#include "ClassAMateria.hpp"

class Cure: public AMateria
{
	public:

		Cure(void);
		Cure(const Cure &other);
		~Cure(void);

		Cure	&operator=(const Cure &other);

		std::string const	&getType(void) const;

		AMateria	*clone(void) const;
		void		use(ICharacter &target);
};

#endif
