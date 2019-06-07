/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 07:47:19 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/07 10:50:18 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SCAVTRAP_HPP
# define	SCAVTRAP_HPP
# include <string>
#include "ClapTrap.hpp"


class ScavTrap : public ClapTrap {
	public:
		ScavTrap(std::string const & name);

		void challengeNewcomer(std::string const & target);


	private:
		struct challenge {
			std::string name;
		};

		static const challenge s_Challenges[];
	protected:

};

#endif
