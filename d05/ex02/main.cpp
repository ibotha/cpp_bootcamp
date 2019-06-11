/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:07:24 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/11 11:41:35 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <random>
#include <ctime>
#define ITERMAX 10000

int main()
{
	std::srand(std::time(0));
	Bureaucrat bob("bob", 30);
	ShrubberyCreationForm form("Home");
	RobotomyRequestForm rbform("Julien");
	PresidentialPardonForm ppform("Obama");

	bob.signForm(form);
	bob.signForm(rbform);
	bob.signForm(ppform);
	bob.executeForm(rbform);
	bob.executeForm(form);
	bob.executeForm(ppform);
}