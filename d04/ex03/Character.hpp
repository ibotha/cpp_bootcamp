/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 00:04:22 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/09 01:10:42 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CHARACTER_HPP
# define	CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
	public:
		Character(std::string name);
		Character(Character const & src);
		virtual ~Character();
		Character & operator=(Character const & src);

		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
	private:
		Character();

		std::string m_Name;
		AMateria *m_Materia[4];

	protected:

};

#endif
