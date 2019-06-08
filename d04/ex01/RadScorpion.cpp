/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 17:01:41 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/08 17:11:34 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"
#include <iostream>

RadScorpion::RadScorpion()
	:Enemy(80, "Rad Scorpion")
{
	std::cout << "* click click click *\n";
}

RadScorpion::RadScorpion(RadScorpion const & src)
	:Enemy(src)
{
	*this = src;
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *\n";
}

RadScorpion & RadScorpion::operator=(RadScorpion const & src) {
	if (this != &src)
	{
	*this = src;
	}
	return (*this);
}
