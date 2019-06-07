/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 07:47:19 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/07 10:38:52 by ibotha           ###   ########.fr       */
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
