/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:04:24 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/11 17:02:37 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"
#include <iostream>

OfficeBlock::OfficeBlock()
	:m_Executor(nullptr), m_Intern(nullptr), m_Signer(nullptr)
{

}

OfficeBlock::OfficeBlock(Intern *intern, Bureaucrat *signer, Bureaucrat *executor)
	:m_Executor(executor), m_Intern(intern), m_Signer(signer)
{

}

OfficeBlock::OfficeBlock(OfficeBlock const & src)
{
	*this = src;	
}

OfficeBlock::~OfficeBlock() {}

OfficeBlock & OfficeBlock::operator=(OfficeBlock const & src) {
	if (this != &src)
	{
	*this = src;
	}
	return (*this);
}

void OfficeBlock::setIntern(Intern &intern)
{
	m_Intern = &intern;
}

void OfficeBlock::setExecutor(Bureaucrat &executor)
{
	m_Executor = &executor;
}

void OfficeBlock::setSigner(Bureaucrat &signer)
{
	m_Signer = &signer;
}

Intern const &OfficeBlock::getIntern() const
{
	return *m_Intern;
}

Bureaucrat const &OfficeBlock::getExecutor() const
{
	return *m_Executor;
}

Bureaucrat const &OfficeBlock::getSigner() const
{
	return *m_Signer;
}

void OfficeBlock::doBureaucracy(std::string const &form, std::string const &target)
{
	if (!m_Executor || !m_Intern || !m_Signer)
	{
		std::cout << "not enough staff" << std::endl;
		return;
	}
	Form *f = m_Intern->makeForm(form, target);
	if (f)
	{
		m_Signer->signForm(*f);
		m_Executor->executeForm(*f);
		delete f;
	}
	
}
