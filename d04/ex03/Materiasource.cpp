/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materiasource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 08:37:09 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/09 08:57:26 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
	:m_Materia({nullptr, nullptr, nullptr, nullptr})
{
	
}

MateriaSource::MateriaSource(MateriaSource const & src) {
	*this = src;	
}

MateriaSource::~MateriaSource() {}

MateriaSource & MateriaSource::operator=(MateriaSource const & src) {
	if (this != &src)
	{
	*this = src;
	}
	return (*this);
}


void MateriaSource::learnMateria(AMateria* m)
{
	for(int i = 0; i < 4; i++)
	{
		if (!m_Materia[i])
			m_Materia[i] = m;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{

}
