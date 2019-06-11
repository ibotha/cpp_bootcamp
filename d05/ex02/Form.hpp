/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 09:08:07 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/11 10:43:57 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FORM_HPP
# define	FORM_HPP

# include <exception>
# include <string>
#include "Bureaucrat.hpp"

class Form {
	public:
		Form(std::string const name, std::string const target, int signGrade, int executeGrade);
		Form(Form const & src);
		~Form();
		Form & operator=(Form const & src);

		class GradeTooLowException : public std::exception {
			const char * what () const throw ();
		};
		
		class GradeTooHighException : public std::exception {
			const char * what () const throw ();
		};
		
		class NotSignedException : public std::exception {
			const char * what () const throw ();
		};
		
		class ActionNotPossibleException : public std::exception {
			const char * what () const throw ();
		};

		int getSignGrade() const;
		int getExecuteGrade() const;
		bool isSigned() const;
		std::string const &getName() const;
		std::string const &getTarget() const;

		void beSigned(Bureaucrat const &b);
		void execute(Bureaucrat const &executor);

		virtual bool action(Bureaucrat const &executor) = 0;

	private:
		const int m_SignGrade;
		const int m_ExecuteGrade;
		bool m_Signed;
		std::string const m_Name;
		std::string const m_Target;
	protected:
		Form();

};


std::ostream& operator<<(std::ostream& os, const Form& dt);

#endif
