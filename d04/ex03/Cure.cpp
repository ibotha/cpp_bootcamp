/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 23:39:51 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/09 08:33:18 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure()
	:AMateria("ice")
{

}

Cure::Cure(Cure const & src)
	:AMateria(src)
{
}

Cure::~Cure() {}

Cure & Cure::operator=(Cure const & src) {
	if (this != &src)
    {
		*this = src;
    }
	return (*this);
}

void Cure::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout << "* heals " << target.getName() << "’s wounds *\n";
}
