/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:07:24 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/11 17:03:39 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "CentralBureaucracy.hpp"
#include <iostream>
#include <random>
#include <ctime>
#define ITERMAX 10000

int main()
{
	Intern idiotOne;
	Bureaucrat hermes = Bureaucrat("Hermes Conrad", 5);
	Bureaucrat bob = Bureaucrat("Bobby Bobson", 5);
	Bureaucrat g = Bureaucrat("d", 5);
	Bureaucrat a = Bureaucrat("a", 5);
	Bureaucrat t = Bureaucrat("s", 5);
	Bureaucrat r = Bureaucrat("r", 5);
	CentralBureaucracy cb;

	cb.addBureaucrat(hermes);
	cb.addBureaucrat(bob);
	cb.addBureaucrat(g);
	cb.addBureaucrat(a);
	cb.addBureaucrat(t);
	cb.addBureaucrat(r);
	cb.addBureaucrat(t);
	cb.addBureaucrat(r);
	cb.addBureaucrat(t);
	cb.addBureaucrat(r);
	cb.addBureaucrat(t);
	cb.addBureaucrat(r);
	cb.queueUp("presidential pardon", "Gregory");
	cb.queueUp("shrubbery creation", "TH");
	cb.queueUp("robotomy request", "robo");
	cb.queueUp("presidential pardon", "Gregory");
	cb.queueUp("presidential pardon", "Gregory");
	cb.doBureaucracy();
}