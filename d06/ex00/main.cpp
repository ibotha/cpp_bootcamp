/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:07:24 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/12 11:55:33 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <cmath>
#define ITERMAX 10000

std::string charPrint(double db)
{
	std::string ret;

	if (std::isnan(db) || !std::isfinite(db))
		return "Impossible";
	else if (!std::isprint(db))
		return "Non displayable";
	ret += "'";
	ret += static_cast<char>(db);
	ret += "'";
	return ret;
}

std::string intPrint(double db)
{
	if (std::isnan(db) || !std::isfinite(db))
		return "Impossible";
	else
		return std::to_string(static_cast<int>(db));
}

std::string floatPrint(double db)
{
	std::stringstream ss;
	ss << static_cast<float>(db);
	if (db == std::floor(db))
		ss << ".0";
	return ss.str();
}

std::string doublePrint(double db)
{
	std::stringstream ss;
	ss << static_cast<double>(db);
	if (db == std::floor(db))
		ss << ".0";
	return ss.str();
}

int main(int ac, char **av)
{
	if (ac < 2)
		return 0;
	double d;
	try
	{
		d = std::stod(av[1]);
	}
	catch (std::invalid_argument &e)
	{
		std::stringstream ss;
		ss << av[1];
		char c;
		ss >> c;
		if (c == '\'')
		{
			ss >> c;
			if (c == '\\')
				ss >> c;
			char temp;
			ss >> temp;
			if (temp == '\'')
				d = static_cast<double>(c);
			else
			{
				std::cout << "Invalid input" << std::endl;
				return 0;
			}
			
		}
		else
		{
			std::cout << "Invalid input" << std::endl;
			return 0;
		}
	}
	
	std::cout << "char: " << charPrint(d) << std::endl;
	std::cout << "int: " << intPrint(d) << std::endl;
	std::cout << "float: " << floatPrint(d) << std::endl;
	std::cout << "double: " << doublePrint(d) << std::endl;
}
