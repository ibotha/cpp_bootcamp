/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 20:29:10 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/08 20:57:14 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"
#include <iostream>

TacticalMarine::TacticalMarine()
{
	std::cout << "Tactical Marine ready for battle\n";
}

TacticalMarine::TacticalMarine(TacticalMarine const & src) {
	*this = src;
}

TacticalMarine::~TacticalMarine()
{
	std::cout << "Aaargh...\n";
}

TacticalMarine & TacticalMarine::operator=(TacticalMarine const & src) {
	if (this != &src)
    {
	*this = src;
    }
	return (*this);
}

ISpaceMarine* TacticalMarine::clone() const
{
	return new TacticalMarine(*this);
}

void TacticalMarine::battleCry() const
{
	std::cout << "For the holy PLOT !\n";
}

void TacticalMarine::rangedAttack() const
{
	std::cout << "* attacks with bolter *\n";
}

void TacticalMarine::meleeAttack() const
{
	std::cout << "* attacks with chainsword *\n";
}
