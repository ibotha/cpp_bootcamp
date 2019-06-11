#include "ShrubberyCreationForm.hpp"
#include <string>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	:Form("Shrubbery Creation Form", target, 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &f)
	:Form(f)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	if (&src != this)
	{
		*this = src;
	}
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm()
	:Form("Shrubbery Creation Form", "PNP", 145, 137)
{

}

bool ShrubberyCreationForm::action(Bureaucrat const &executor)
{
	(void)executor;
	std::ofstream out(getTarget() + "_shrubbery");
	if (!out)
		return false;
	out <<	"     \\|/**********\\|/          \n"
			"\\|/   *************     \\|/    \n"
			"   \\*****************          \n"
			"   ******************* \\|/     \n"
			"    ******************/   \\|/  \n"
			"   \\|/**************    \\|/    \n"
			"        \\*/  | /    \\|/        \n"
			"    \\|/   |[{}]|        \\|/    \n"
			"          |[||]|    \\|/        \n"
			"     \\|/  |[][]|               \n"
			"          |[][]|   \\|/         \n"
			"   \\|/   /|[][]|\\/     \\|/     \n"
			"       //|||[]|||\\            \n"
			"     ///|||[[]]|||\\\\\\      \\|/ \n";
	return true;
}
