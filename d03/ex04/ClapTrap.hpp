/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 07:47:19 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/07 14:15:46 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CLAPTRAP_HPP
# define	CLAPTRAP_HPP
# include <string>


class ClapTrap {
	public:
		ClapTrap(std::string const & name);
		ClapTrap(ClapTrap const & src);
		~ClapTrap();
		ClapTrap & operator=(ClapTrap const & src);

		void meleeAttack(std::string const &target);
		void rangedAttack(std::string const &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void setHitPoints(unsigned int hp);
		void setMaxHitPoints(unsigned int mhp);
		void setEnergyPoints(unsigned int ep);
		void setMaxEnergyPoints(unsigned int mep);
		void setLevel(unsigned int level);
		void setMeleeDamage(unsigned int md);
		void setRangedDamage(unsigned int rd);
		void setArmourDamageReduction(unsigned int adr);
		void setName(std::string const & name);

		unsigned int getHitPoints() const;
		unsigned int getMaxHitPoints() const;
		unsigned int getEnergyPoints() const;
		unsigned int getMaxEnergyPoints() const;
		unsigned int getLevel() const;
		unsigned int getMeleeDamage() const;
		unsigned int getRangedDamage() const;
		unsigned int getArmourDamageReduction() const;
		std::string const &getName() const;

	protected:
		unsigned int m_HitPoints,
		m_MaxHitPoints,
		m_EnergyPoints,
		m_MaxEnergyPoints,
		m_Level,
		m_MeleeDamage,
		m_RangedDamage,
		m_ArmourDamageReduction;

		std::string m_Name;

};

#endif
