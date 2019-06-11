/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 09:08:13 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/11 14:23:06 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

Form::Form()
	:m_SignGrade(150), m_ExecuteGrade(150), m_Signed(false), m_Name("PNP"), m_Target("PNP")
{
}

Form::Form(std::string name, std::string target, int signGrade, int executeGrade)
	:m_SignGrade(signGrade), m_ExecuteGrade(executeGrade), m_Signed(false), m_Name(name), m_Target(target)
{
	if (signGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150)
		throw GradeTooLowException();
	if (executeGrade < 1)
		throw GradeTooHighException();
	if (executeGrade > 150)
		throw GradeTooLowException();
}

Form::Form(Form const &src)
	:m_SignGrade(src.m_SignGrade), m_ExecuteGrade(src.m_ExecuteGrade), m_Signed(src.m_Signed), m_Name(src.m_Name), m_Target(src.m_Target)
{
}

Form::~Form()
{
}

Form &Form::operator=(Form const &src)
{
	if (this != &src)
	{
		*this = src;
	}
	return (*this);
}

std::string const &Form::getName() const
{
	return m_Name;
}

std::string const &Form::getTarget() const
{
	return m_Target;
}

int Form::getSignGrade() const
{
	return m_SignGrade;
}

int Form::getExecuteGrade() const
{
	return m_ExecuteGrade;
}

bool Form::isSigned() const
{
	return m_Signed;
}

void Form::beSigned(Bureaucrat const &b)
{
	int grade = b.getGrade();
	if (grade > m_SignGrade)
		throw GradeTooHighException();
	m_Signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Form grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form grade too low";
}

const char *Form::NotSignedException::what() const throw()
{
	return "Form not signed";
}

const char *Form::ActionNotPossibleException::what() const throw()
{
	return "Form action not possible";
}

std::ostream &operator<<(std::ostream &os, const Form &dt)
{
	os << dt.getName() << ", " << dt.getTarget() << ": " << dt.getSignGrade() << ", " << dt.getExecuteGrade() << " " << (dt.isSigned() ? "is signed" : "is not signed");
	return os;
}

void Form::execute(Bureaucrat const &executor)
{
	int grade = executor.getGrade();
	if (grade > getExecuteGrade())
		throw GradeTooHighException();
	if (!m_Signed)
		throw NotSignedException();
	if (!action(executor))
		throw ActionNotPossibleException();
}
