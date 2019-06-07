/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 08:23:28 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/07 09:52:21 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <random>

int main()
{
	std::srand(std::time(0));
	FragTrap bob("bob");
	bob.meleeAttack("greg");
	bob.rangedAttack("greg");
	bob.takeDamage(40);
	bob.takeDamage(2);
	bob.beRepaired(500);
	bob.takeDamage(106);
	bob.vaulthunter_dot_exe("billy");
}