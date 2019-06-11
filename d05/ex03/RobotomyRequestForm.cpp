#include "RobotomyRequestForm.hpp"
#include <string>
#include <iostream>
#include <random>
RobotomyRequestForm::RobotomyRequestForm(std::string target)
	:Form("Robotomy Request Form", target, 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &f)
	:Form(f)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	if (&src != this)
	{
		*this = src;
	}
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm()
	:Form("Robotomy Request Form", "PNP", 72, 45)
{

}

bool RobotomyRequestForm::action(Bureaucrat const &executor)
{
	(void)executor;
	while(std::rand() % 3)
	{
		std::cout << "* bzzzzzt *" << std::endl;
	}
	if (std::rand() % 2)
		std::cout << getTarget() << " has been robotomized" << std::endl;
	else
		std::cout << getTarget() << " could not be robotomized" << std::endl;
	return true;
}
