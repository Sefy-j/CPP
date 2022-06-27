/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassContact.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:17:47 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/06/27 17:25:03 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_CONTACT_HPP
# define CLASS_CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
	public:

		Contact(void);
		~Contact(void);

		bool	createcontact(void);
		bool	checkcontact(void);
		void	showcontactindex(void);
		void	printcontact(void);
	
	private:

		std::string	fname;
		std::string	lname;
		std::string	nick;
		std::string	phnbr;
		std::string	secret;

		bool	errorcreating(int i);
};

#endif