/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassBrain.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:12:45 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/07 12:05:39 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSBRAIN_HPP
# define CLASSBRAIN_HPP

#include <iostream>

class Brain
{
	public:

		Brain(void);
		Brain(const Brain &other);
		~Brain(void);

		Brain	&operator=(const Brain &other);

		std::string	*getIdeas(void);

		void	copyIdeas(const std::string *ideas);
		void	addIdeas(std::string idea);
		void	printIdeas(void) const;
	
	private:

		std::string _ideas[100];
};

#endif