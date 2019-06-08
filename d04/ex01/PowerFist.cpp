/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:22:11 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/08 10:30:01 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"
#include <iostream>

PowerFist::PowerFist()
	:AWeapon("Power Fist", 50, 8)
{
}

PowerFist::PowerFist(PowerFist const &src)
{
	*this = src;
}

PowerFist::~PowerFist()
{
}

PowerFist &PowerFist::operator=(PowerFist const &src)
{
	if (this != &src)
	{
		*this = src;
	}
	return (*this);
}

void PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *\n";
}
