/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 07:47:19 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/07 15:21:09 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FRAGTRAP_HPP
# define	FRAGTRAP_HPP
# include "ClapTrap.hpp"
# include <string>


class FragTrap : public ClapTrap
{
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

	private:
		struct ability {
			std::string name;
			unsigned int damage;
		};

		static const ability s_VaultHunterAbilities[];
		
	protected:

};

#endif