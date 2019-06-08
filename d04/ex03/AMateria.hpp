/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 23:00:11 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/08 23:58:13 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		AMATERIA_HPP
# define	AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class AMateria {
	public:
		AMateria & operator=(AMateria const & src);
		AMateria(AMateria const & src);
		virtual ~AMateria();

		//[...]
		std::string const & getType() const; //Returns the materia type
		unsigned int getXP() const; //Returns the Materia's XP
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
	private:
		std::string m_Type;
		AMateria();

	protected:
		unsigned int m_XP;
		AMateria(std::string const & type);

};

#endif
