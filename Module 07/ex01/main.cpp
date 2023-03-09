/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:29:37 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/20 13:13:53 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

class Awesome
{
	public:

		Awesome( void ) : _n( 42 ) { return; }

		int get( void ) const { return this->_n; }

	private:

		int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }

int main() 
{
	int tab[] = { 0, 1, 2, 3, 4 };
	Awesome tab2[5];
	std::string str[3] = {"Hello", "Bye", "Nice"};

	iter<int>( tab, 5, print );
	std::cout << std::endl;
	iter<Awesome>( tab2, 5, print );
	std::cout << std::endl;
	iter<std::string>(str, 3, print);
	return 0;
}