/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:12:00 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/19 19:14:22 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassA.hpp"
#include "ClassB.hpp"
#include "ClassC.hpp"
#include <cstdlib>
#include <iostream>

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "Base is type A" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Base is not type A" << std::endl;
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "Base is type B" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Base is not type B" << std::endl;
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "Base is type C" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Base is not type C" << std::endl;
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Base is type A" << std::endl;
	else
		std::cout << "Base is not type A" << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << "Base is type B" << std::endl;
	else
		std::cout << "Base is not type B" << std::endl;
	if (dynamic_cast<C *>(p))
		std::cout << "Base is type C" << std::endl;
	else
		std::cout << "Base is not type C" << std::endl;
		
}

Base *generate(void)
{
	int	n;

	srand (time(NULL));
	n = rand() % 3;
	if (n == 0)
	{
		std::cout << "Type A generated" << std::endl;
		return (new A);
	}
	else if (n == 1)
	{
		std::cout << "Type B generated" << std::endl;
		return (new B);
	}
	else
	{
		std::cout << "Type C generated" << std::endl;
		return (new C);
	}
}

int	main(void)
{
	Base	*base;

	base = generate();
	std::cout << std::endl;
	identify(base);
	std::cout << std::endl;
	identify(*base);
	delete base;
	return (0);
}
