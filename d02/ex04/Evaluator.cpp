/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Evaluator.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:47:37 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/06 18:44:28 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Evaluator.hpp"
#include <sstream>

Evaluator::Evaluator(std::string expr)
	:m_Expression(expr)
{
	if (m_Expression.length() == 0)
		m_Valid = false;
	else
	{
		prioritise('/');
		prioritise('*');
		prioritise('+');
		std::stringstream ss;
		ss << m_Expression;
		m_Valid = validate(ss);
	}
	
}

int Evaluator::validate(std::stringstream &ss)
{
	bool hasnum = false;
	int pos = ss.tellg();
	while (!ss.eof())
	{
		Fixed a;
		char c = '\0';
		ss >> a;
		if (ss.fail()) {
			ss.clear();
			ss.seekg(pos);
			ss >> c;
			pos = ss.tellg();
			if (c == ')') {
				return 3;
			} else if (c == '(') {
				if (hasnum) {
					return 0;
				}
				if (!validate(ss)) {
					return 0;
				}
				pos = ss.tellg();
				hasnum = 1;
			} else if (c == '+' || c == '-' || c == '*' || c == '/') {
				if (!hasnum) {
					return 0;
				}
				hasnum = false;
			} else {
				if (ss.eof()) {
					return hasnum;
				}
				return 0;
			}
		} else {
			if (hasnum) {
				return 0;
			}
			hasnum = true;
			pos = ss.tellg();
		}
	}
	return hasnum;
}

Fixed Evaluator::evaluate(std::stringstream &ss)
{
	bool started = false;
	Fixed ret;
	int pos = ss.tellg();
	char o = '\0';
	Fixed a;
	while (!ss.eof())
	{
		ss >> a;
		char c = '\0';
		if (ss.fail()) {
			ss.clear();
			ss.seekg(pos);
			ss >> c;
			pos = ss.tellg();
			if (c == ')') {
				return ret;
			} else if (c == '(') {
				a = evaluate(ss);
				pos = ss.tellg();
				if (!started) {
					ret = a;
					started = true;
				} else {
					switch (o)
					{
					case '*':
						ret = ret * a;
						break;
					case '/':
						ret = ret / a;
						break;
					case '-':
						ret = ret - a;
						break;
					case '+':
						ret = ret + a;
						break;
					default:
						break;
					}
					o = '\0';
				}
			} else if (c == '+' || c == '-' || c == '*' || c == '/') {
				o = c;
			} else {
				if (!started) {
					ret = a;
				}
				return ret;
			}
		} else {
			pos = ss.tellg();
			if (!started) {
				ret = a;
				started = true;
			} else {
				switch (o)
				{
				case '*':
					ret = ret * a;
					break;
				case '/':
					ret = ret / a;
					break;
				case '-':
					ret = ret - a;
					break;
				case '+':
					ret = ret + a;
					break;
				default:
					break;
				}
				o = '\0';
			}
		}
	}
	if (!started) {
		ret = a;
	}
	return ret;
}

Evaluator::Evaluator(Evaluator const & src) {
	*this = src;	
}

Evaluator::~Evaluator() {}

Evaluator & Evaluator::operator=(Evaluator const & src) {
	if (this != &src)
	{
		*this = src;
	}
	return (*this);
}

bool Evaluator::valid() const
{
	if (m_Valid == 3)
		return false;
	return m_Valid ? true : false;
}

Fixed Evaluator::getResult()
{
	std::stringstream ss;
	ss << m_Expression;
	return evaluate(ss);
}

void Evaluator::prioritise(const char &c)
{
	size_t i = 0;
	while (i < m_Expression.length())
	{
		i = m_Expression.find(c, i);
		if (i == std::string::npos)
			return;
		size_t bracket = 0;
		bool hit = false;
		size_t j;
		for (j = i + 1; j < m_Expression.length(); j++)
		{
			char c = m_Expression[j];
			if (c == '(') {
				hit = true;
				bracket++;
			} else if (c == ')') {
				bracket--;
				if (bracket < 1) {
					break;
				}
			} else if (std::iswspace(c)) {
				if (hit && bracket < 1)
					break;
			} else {
				hit = true;
			}
		}
		hit = false;
		bracket = 0;
		m_Expression.insert(j, ")");
		for (j = i - 1; j < m_Expression.length(); j--)
		{
			char c = m_Expression[j];
			if (c == ')') {
				hit = true;
				bracket++;
			} else if (c == '(') {
				bracket--;
				if (bracket < 1) {
					break;
				}
			} else if (std::iswspace(c)) {
				if (hit && bracket < 1)
					break;
			} else {
				hit = true;
			}
		}
		m_Expression.insert(j + 1, "(");
		i+= 2;
	}
}