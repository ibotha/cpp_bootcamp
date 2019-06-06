/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 08:23:28 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/06 14:57:24 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Evaluator.hpp"
#include <iostream>

int main(int ac, char** av) {

	if (ac < 2)
	{
		std::cout << "usage: ./eval_expr [expression]\n";
		return -1;
	}

	Evaluator e(av[1]);

	if (!e.valid())
	{
		std::cout << "Invalid Expression\n";
		return -1;
	}

	std::cout << e.getResult() << "\n";
}