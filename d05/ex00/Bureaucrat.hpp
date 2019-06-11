/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 09:08:44 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/11 10:01:28 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		BUREAUCRAT_HPP
# define	BUREAUCRAT_HPP

# include <exception>
# include <string>

class Bureaucrat {
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat();
		Bureaucrat & operator=(Bureaucrat const & src);

		class GradeTooLowException : public std::exception {
			const char * what () const throw ();
		};
		
		class GradeTooHighException : public std::exception {
			const char * what () const throw ();
		};

		int getGrade() const;
		std::string const &getName() const;

		Bureaucrat operator++();
		Bureaucrat operator++(int);
		Bureaucrat operator--();
		Bureaucrat operator--(int);
	private:
		Bureaucrat();
		int m_Grade;
		const std::string m_Name;
	protected:

};


std::ostream& operator<<(std::ostream& os, const Bureaucrat& dt);

#endif
