/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 07:47:19 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/07 15:37:27 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		NINJATRAP_HPP
# define	NINJATRAP_HPP
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <string>


class NinjaTrap : virtual public ClapTrap
{
	public:
		NinjaTrap(std::string const & name);
		NinjaTrap(NinjaTrap const & src);
		~NinjaTrap();
		NinjaTrap & operator=(NinjaTrap const & src);

		void meleeAttack(std::string const &target);
		void rangedAttack(std::string const &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void ninjaShoebox(ScavTrap & target);
		void ninjaShoebox(FragTrap & target);
		void ninjaShoebox(NinjaTrap & target);

	private:
		struct ability {
			std::string name;
			unsigned int damage;
		};

		static const ability s_VaultHunterAbilities[];
		
	protected:

};

#endif

