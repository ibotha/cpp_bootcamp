/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aweapon.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10/05/32 by ibotha          #+#    #+#             */
/*   Updated: 2019/06/08 10/05/32 by ibotha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		AWEAPON_HPP
# define	AWEAPON_HPP

# include <string>

class AWeapon {
	public:
		AWeapon(AWeapon const & src);
		AWeapon & operator=(AWeapon const & src);
		AWeapon(std::string const & name, int apcost, int damage);
		virtual ~AWeapon();

		std::string const &getName() const;
		int getAPCost() const;
		int getDamage() const;
		virtual void attack() const = 0;

	private:
		std::string m_Name;
		int m_Damage;
		int m_APCost;
	protected:
		AWeapon();

};

#endif
