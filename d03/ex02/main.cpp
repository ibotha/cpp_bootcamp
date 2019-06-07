/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 08:23:28 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/07 10:13:15 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <random>

int main()
{
	std::srand(std::time(0));
	FragTrap frag("Frag");
	ScavTrap scav("Scav");
	frag.meleeAttack(scav.getName());
	frag.rangedAttack(scav.getName());
	frag.takeDamage(40);
	frag.takeDamage(2);
	frag.beRepaired(500);
	frag.takeDamage(106);
	frag.vaulthunter_dot_exe(scav.getName());
	scav.meleeAttack(frag.getName());
	scav.rangedAttack(frag.getName());
	scav.takeDamage(40);
	scav.takeDamage(2);
	scav.beRepaired(500);
	scav.takeDamage(106);
	scav.challengeNewcomer("billy");
}