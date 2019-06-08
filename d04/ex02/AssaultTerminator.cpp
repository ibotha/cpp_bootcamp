/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 20:29:10 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/08 20:57:14 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"
#include <iostream>

AssaultTerminator::AssaultTerminator()
{
	std::cout << "* teleports from space *\n";
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const & src) {
	*this = src;
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout << "I’ll be back ...\n";
}

AssaultTerminator & AssaultTerminator::operator=(AssaultTerminator const & src) {
	if (this != &src)
    {
	*this = src;
    }
	return (*this);
}

ISpaceMarine* AssaultTerminator::clone() const
{
	return new AssaultTerminator(*this);
}

void AssaultTerminator::battleCry() const
{
	std::cout << "This code is unclean. PURIFY IT !\n";
}

void AssaultTerminator::rangedAttack() const
{
	std::cout << "* does nothing *\n";
}

void AssaultTerminator::meleeAttack() const
{
	std::cout << "* attacks with chainfists *\n";
}
