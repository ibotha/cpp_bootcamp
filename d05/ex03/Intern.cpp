/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 13:41:46 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/11 14:20:57 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(Intern const & src) {
	*this = src;	
}

Intern::~Intern() {}

Intern & Intern::operator=(Intern const & src) {
	if (this != &src)
	{
	*this = src;
	}
	return (*this);
}

Form *Intern::makeForm(std::string const &formType, std::string const &target)
{
	if (formType == "shrubbery creation")
	{
		Form *f = new ShrubberyCreationForm(target);
		std::cout << "Intern makes " << *f << std::endl;
		return f;
	}
	else if (formType == "presidential pardon")
	{
		Form *f = new PresidentialPardonForm(target);
		std::cout << "Intern makes " << *f << std::endl;
		return f;
	}
	else if (formType == "robotomy request")
	{
		Form *f = new RobotomyRequestForm(target);
		std::cout << "Intern makes " << *f << std::endl;
		return f;
	}
	std::cout << "Intern does not understand \"" << formType << "\"" << std::endl;
	return nullptr;
}
