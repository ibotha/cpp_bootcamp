/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 07:47:19 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/07 10:12:49 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SCAVTRAP_HPP
# define	SCAVTRAP_HPP
# include <string>


class ScavTrap {
	public:
		ScavTrap(std::string const & name);
		ScavTrap(ScavTrap const & src);
		~ScavTrap();
		ScavTrap & operator=(ScavTrap const & src);

		void meleeAttack(std::string const &target);
		void rangedAttack(std::string const &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void challengeNewcomer(std::string const & target);

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
		struct challenge {
			std::string name;
		};

		static const challenge s_Challenges[];

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
