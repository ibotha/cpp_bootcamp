/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:07:24 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/11 14:33:22 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>
#include <random>
#include <ctime>
#define ITERMAX 10000

int main()
{
	std::srand(std::time(0));
	Bureaucrat bob("bob", 30);
	Intern intern;
	Form *f;
	
	f = intern.makeForm("shrubbery creation", "home");
	if (f)
	{
		bob.signForm(*f);
		bob.executeForm(*f);
	}
}