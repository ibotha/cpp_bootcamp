/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 11:24:33 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/11 11:25:11 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <string>

class RobotomyRequestForm : public Form {
	public:

		RobotomyRequestForm(std::string target);
		RobotomyRequestForm( RobotomyRequestForm const &f);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=( RobotomyRequestForm const &src);

		virtual bool action(Bureaucrat const &executor);

	private:
	
		RobotomyRequestForm();
		
	protected:
};

#endif