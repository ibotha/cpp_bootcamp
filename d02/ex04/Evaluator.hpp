/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Evaluator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:47:15 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/06 17:41:33 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		EVALUATOR_HPP
# define	EVALUATOR_HPP
#include <string>
#include "Fixed.hpp"
#include <iostream>

class Evaluator {
	public:
		Evaluator(std::string expr);
		Evaluator(Evaluator const & src);

		bool valid() const;
		Fixed getResult();

		Fixed evaluate(std::stringstream &ss);

		Fixed operate(Fixed const &a, const char &o, Fixed const &b);

		~Evaluator();
		Evaluator & operator=(Evaluator const & src);
	private:
		std::string m_Expression;
		int m_Valid;
		int validate(std::stringstream &ss);
		void prioritise(const char &c);
	protected:

};

#endif
