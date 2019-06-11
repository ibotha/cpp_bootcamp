/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 11:24:33 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/11 11:25:11 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
#include <string>

class PresidentialPardonForm : public Form {
	public:

		PresidentialPardonForm(std::string target);
		PresidentialPardonForm( PresidentialPardonForm const &f);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=( PresidentialPardonForm const &src);

		virtual bool action(Bureaucrat const &executor);

	private:
	
		PresidentialPardonForm();
		
	protected:
};

#endif