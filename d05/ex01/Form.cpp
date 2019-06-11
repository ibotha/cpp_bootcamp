/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 09:08:13 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/11 09:57:58 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

Form::Form()
	:m_SignGrade(150), m_ExecuteGrade(150), m_Signed(false), m_Name("PNP")
{
}

Form::Form(std::string name, int signGrade, int executeGrade)
	:m_SignGrade(signGrade), m_ExecuteGrade(executeGrade), m_Signed(false), m_Name(name)
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
	:m_SignGrade(src.m_SignGrade), m_ExecuteGrade(src.m_ExecuteGrade), m_Signed(src.m_Signed)
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

std::ostream &operator<<(std::ostream &os, const Form &dt)
{
	os << dt.getName() << ", Sign: " << dt.getSignGrade() << " Exe: " << dt.getExecuteGrade() << " " << (dt.isSigned() ? "is signed" : "is not signed") << ".";
	return os;
}
