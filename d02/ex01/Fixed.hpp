#ifndef		FIXED_HPP
# define	FIXED_HPP
#include <iostream>


class Fixed {
	public:
		Fixed(float const &n);
		Fixed(int const &n);
		Fixed();
		Fixed(Fixed const & src);
		~Fixed();
		Fixed & operator=(Fixed const & src);

		int getRawBits() const;
		void setRawBits(int number);
		int toInt() const;
		float toFloat() const;
	private:
		int m_Number;
		static const int s_Point;

	protected:

};

std::ostream &operator<<(std::ostream &o, Fixed const &f);

#endif