/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 17/18/32 by ibotha          #+#    #+#             */
/*   Updated: 2019/06/08 17/18/32 by ibotha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CHARACTER_HPP
# define	CHARACTER_HPP

#include <string>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character {
	public:
		Character(Character const & src);
		~Character();
		Character & operator=(Character const & src);
		Character(std::string const &name);

		void recoverAP();
		void equip(AWeapon*);
		void attack(Enemy*);
		std::string const &getName() const;
		int getAP() const;
		const AWeapon *getWeapon() const;

	private:
		Character();
		std::string m_Name;

		int m_AP;
		AWeapon *m_Weapon;
	protected:

};

std::ostream &operator<<(std::ostream &out, Character const &c);

#endif
