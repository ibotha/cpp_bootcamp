/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:07:24 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/11 09:57:29 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#define ITERMAX 10000

int main()
{
	Bureaucrat bob("bob", 50);
	Form easy("ez", 150, 150);
	Form medium("md", 50, 50);
	Form hard("hd", 1, 1);

	bob.signForm(easy);
	bob.signForm(medium);
	bob.signForm(hard);
}