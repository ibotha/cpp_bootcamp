/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 07:47:19 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/07 15:35:31 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SUPERTRAP_HPP
# define	SUPERTRAP_HPP
# include <string>
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"


class SuperTrap : public FragTrap, public NinjaTrap {
	public:
		SuperTrap(std::string const & name);

		SuperTrap(SuperTrap const & src);
		~SuperTrap();
		SuperTrap & operator=(SuperTrap const & src);

		void meleeAttack(std::string const &target);
		void rangedAttack(std::string const &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);


	private:
		struct challenge {
			std::string name;
		};

		static const challenge s_Challenges[];
	protected:

};

#endif
