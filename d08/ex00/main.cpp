/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:07:24 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/12 13:28:15 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main( void ) {
	std::vector<int> v;
	std::list<int> l;
	std::deque<int> d;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	try
	{
		easyfind(v, 3);
		easyfind(v, 6);
	}
	catch (std::exception &e)
	{
		std::cout << "stuff not found\n";
	}
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	try
	{
		easyfind(l, 3);
		easyfind(l, 6);
	}
	catch (std::exception &e)
	{
		std::cout << "stuff not found\n";
	}
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_back(4);
	d.push_back(5);
	try
	{
		easyfind(d, 3);
		easyfind(d, 6);
	}
	catch (std::exception &e)
	{
		std::cout << "stuff not found\n";
	}
}

