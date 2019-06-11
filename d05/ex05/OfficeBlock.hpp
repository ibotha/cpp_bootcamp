/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:05:06 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/11 16:25:07 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		OFFICEBLOCK_HPP
# define	OFFICEBLOCK_HPP

#include "Intern.hpp"
#include "Bureaucrat.hpp"

class OfficeBlock {
	public:
		OfficeBlock();
		OfficeBlock(Intern *intern, Bureaucrat *signer, Bureaucrat *executor);
		~OfficeBlock();

		void setIntern(Intern &intern);
		void setExecutor(Bureaucrat &executor);
		void setSigner(Bureaucrat &signer);
		Intern const &getIntern() const;
		Bureaucrat const &getExecutor() const;
		Bureaucrat const &getSigner() const;

		void doBureaucracy(std::string const &form, std::string const &target);

	private:
		OfficeBlock(OfficeBlock const & src);
		OfficeBlock & operator=(OfficeBlock const & src);
		Bureaucrat *m_Executor;
		Intern *m_Intern;
		Bureaucrat *m_Signer;

	protected:

};

#endif
