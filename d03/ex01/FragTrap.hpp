/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 07:47:19 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/07 09:50:20 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FRAGTRAP_HPP
# define	FRAGTRAP_HPP
# include <string>


class FragTrap {
	public:
		FragTrap(std::string const & name);
		FragTrap(FragTrap const & src);
		~FragTrap();
		FragTrap & operator=(FragTrap const & src);

		void meleeAttack(std::string const &target);
		void rangedAttack(std::string const &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void vaulthunter_dot_exe(std::string const & target);

		void setHitPoints(unsigned int hp);
		void setMaxHitPoints(unsigned int mhp);
		void setEnergyPoints(unsigned int ep);
		void setMaxEnergyPoints(unsigned int mep);
		void setLevel(unsigned int level);
		void setMeleeDamage(unsigned int md);
		void setRangedDamage(unsigned int rd);
		void setArmourDamageReduction(unsigned int adr);
		void setName(std::string const & name);

		unsigned int getHitPoints();
		unsigned int getMaxHitPoints();
		unsigned int getEnergyPoints();
		unsigned int getMaxEnergyPoints();
		unsigned int getLevel();
		unsigned int getMeleeDamage();
		unsigned int getRangedDamage();
		unsigned int getArmourDamageReduction();
		std::string const &getName();


	private:
		struct ability {
			std::string name;
			unsigned int damage;
		};

		static const ability s_VaultHunterAbilities[];

		unsigned int m_HitPoints,
		m_MaxHitPoints,
		m_EnergyPoints,
		m_MaxEnergyPoints,
		m_Level,
		m_MeleeDamage,
		m_RangedDamage,
		m_ArmourDamageReduction;

		std::string m_Name;
	protected:

};

#endif
