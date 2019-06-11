#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>
#include <random>
PresidentialPardonForm::PresidentialPardonForm(std::string target)
	:Form("Presidential Pardon Form", target, 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &f)
	:Form(f)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	if (&src != this)
	{
		*this = src;
	}
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm()
	:Form("Presidential Pardon Form", "PNP", 25, 5)
{

}

bool PresidentialPardonForm::action(Bureaucrat const &executor)
{
	(void)executor;
	std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
	return true;
}
