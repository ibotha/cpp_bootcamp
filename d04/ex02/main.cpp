/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 08:23:28 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/08 17:40:55 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"
#include <iostream>
#define ITERMAX 10000

int main()
{
	Character* zaz = new Character("zaz");
	std::cout << *zaz << "\n";
	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	zaz->equip(pr);
	std::cout << *zaz << "\n";
	zaz->equip(pf);
	zaz->attack(b);
	std::cout << *zaz << "\n";
	zaz->equip(pr);
	std::cout << *zaz << "\n";
	zaz->attack(b);
	std::cout << *zaz << "\n";
	zaz->attack(b);
	std::cout << *zaz << "\n";
	return 0;
}