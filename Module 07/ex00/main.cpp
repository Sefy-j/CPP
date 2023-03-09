/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:29:37 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/20 12:13:15 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

class Awesome
{
	public:
	
	Awesome( int n ) : _n( n ) {}

	bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
	bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
	bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
	bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
	bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
	bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }

	int	getN(void) const { return (this->_n); }
	
	private:
	
	int _n;
};

std::ostream &operator<<(std::ostream &out, const Awesome &aw) { out << aw.getN(); return(out); }

int	main(void)
{
	{
		int		a = 0;
		int		b = 1;
		float	c = 2.0f;
		float	d = 3.0f;
		char	e = 'a';
		char	f = 'b';
		Awesome	aw(4);
		Awesome	aw2(5);

		std::cout << "Before swap: " << a << " " << b << std::endl;
		swap<int>(a,b);
		std::cout << "After swap: " << a << " " << b << std::endl;
		std::cout << "Min is: " << min<int>(a, b) << std::endl;
		std::cout << "Max is: " << max<int>(a, b) << std::endl;
		std::cout << std::endl;
		std::cout << "Before swap: " << c << " " << d << std::endl;
		swap<float>(c,d);
		std::cout << "After swap: " << c << " " << d << std::endl;
		std::cout << "Min is: " << min<float>(c, d) << std::endl;
		std::cout << "Max is: " << max<float>(c, d) << std::endl;
		std::cout << std::endl;
		std::cout << "Before swap: " << e << " " << f << std::endl;
		swap<char>(e,f);
		std::cout << "After swap: " << e << " " << f << std::endl;
		std::cout << "Min is: " << min<char>(e, f) << std::endl;
		std::cout << "Max is: " << max<char>(e, f) << std::endl;
		std::cout << std::endl;
		std::cout << "Before swap: " << aw.getN() << " " << aw2.getN() << std::endl;
		swap<Awesome>(aw,aw2);
		std::cout << "After swap: " << aw.getN() << " " << aw2.getN() << std::endl;
		std::cout << "Min is: " << min<Awesome>(aw, aw2) << std::endl;
		std::cout << "Max is: " << max<Awesome>(aw, aw2) << std::endl;
	}
	std::cout << std::endl;
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
		return 0;
	}
}