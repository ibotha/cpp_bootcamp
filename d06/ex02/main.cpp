/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:07:24 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/12 12:41:20 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <random>
#include <ctime>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base *generate()
{
	switch (std::rand() % 3)
	{
	case 0:
		return new A;
		break;
	case 1:
		return new B;
		break;
	case 2:
		return new C;
		break;
	default:
		break;
	}
	return nullptr;
}

void identify_from_pointer(Base * base)
{
	A *a = dynamic_cast<A*>(base);
	if (a)
		std::cout << "A\n";
	else
	{
		B *b = dynamic_cast<B*>(base);
		if (b)
			std::cout << "B\n";
		else
		{
			C *c = dynamic_cast<C*>(base);
			if (c)
				std::cout << "C\n";
		}
	}
}

void identify_from_reference(Base & base)
{
	try
	{
		A &a = dynamic_cast<A&>(base);
		(void)a;
		std::cout << "A\n";
	}
	catch(const std::exception& e)
	{
		try
		{
			B &b = dynamic_cast<B&>(base);
			(void)b;
			std::cout << "B\n";
		}
		catch(const std::exception& e)
		{
			try
			{
				C &c = dynamic_cast<C&>(base);
				(void)c;
				std::cout << "C\n";
			}
			catch(const std::exception& e)
			{
			}
		}
	}
}

int main()
{
	std::srand(std::time(0));
	Base *base = generate();
	identify_from_pointer(base);
	identify_from_reference(*base);
	delete base;
}
