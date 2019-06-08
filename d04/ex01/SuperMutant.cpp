/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 17:01:41 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/08 17:07:53 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"
#include <iostream>

SuperMutant::SuperMutant()
	:Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads !\n";
}

SuperMutant::SuperMutant(SuperMutant const & src)
	:Enemy(src)
{
	*this = src;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh !\n";
}

SuperMutant & SuperMutant::operator=(SuperMutant const & src) {
	if (this != &src)
	{
	*this = src;
	}
	return (*this);
}

void SuperMutant::takeDamage(int amount)
{
	Enemy::takeDamage(amount - 3);
}
