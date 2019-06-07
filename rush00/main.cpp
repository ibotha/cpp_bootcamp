/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 08:23:28 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/07 17:01:32 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Invader.hpp"
#include <random>
#define ITERMAX 10000

int main(void)
{
	std::srand(std::time(0));

	Invader game;

	game.run();
}