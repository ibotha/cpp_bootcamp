/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 08:23:28 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/09 12:47:27 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Game.hpp"


#include <random>
#define ITERMAX 10000

int main(void)
{
	std::srand(std::time(0));

	Game::getInstance()->run();
	delete Game::getInstance();
}