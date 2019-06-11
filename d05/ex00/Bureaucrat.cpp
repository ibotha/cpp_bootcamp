/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 09:08:36 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/11 09:08:36 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat()
	: m_Grade(150), m_Name("No One")
{
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	:m_Grade(grade), m_Name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	*this = src;	
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src) {
	if (this != &src)
	{
	*this = src;
	}
	return (*this);
}

int Bureaucrat::getGrade() const
{
	return m_Grade;
}

std::string const &Bureaucrat::getName() const
{
	return m_Name;
}

const char * Bureaucrat::GradeTooHighException::what() const throw ()
{
	return "Bureaucrat grade too high";
}

const char * Bureaucrat::GradeTooLowException::what() const throw ()
{
	return "Bureaucrat grade too low";
}

Bureaucrat Bureaucrat::operator++()
{
	if (m_Grade > 149)
		throw GradeTooLowException();
	m_Grade++;
	return *this;
}

Bureaucrat Bureaucrat::operator++(int)
{
	if (m_Grade > 149)
		throw GradeTooLowException();
	Bureaucrat old = *this;
	m_Grade++;
	return old;
}

Bureaucrat Bureaucrat::operator--()
{
	if (m_Grade < 2)
		throw GradeTooHighException();
	m_Grade--;
	return *this;
}

Bureaucrat Bureaucrat::operator--(int)
{
	if (m_Grade < 2)
		throw GradeTooHighException();
	Bureaucrat old = *this;
	m_Grade--;
	return old;
}
std::ostream& operator<<(std::ostream& os, const Bureaucrat& dt)
{
    os << dt.getName() << ", bureaucrat grade " << dt.getGrade() << ".";
    return os;
}
