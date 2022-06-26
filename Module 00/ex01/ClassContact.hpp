/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassContact.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:17:47 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/06/26 19:49:01 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_CONTACT_HPP
# define CLASS_CONTACT_HPP

#include <string>

class Contact
{
	public:

	std::string	fname;
	std::string	lname;
	std::string	nick;
	std::string	phnbr;
	std::string	secret;

	Contact(void);
	~Contact(void);
};

#endif