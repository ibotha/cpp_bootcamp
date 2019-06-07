#ifndef		FIXED_HPP
# define	FIXED_HPP
#include <iostream>


class Fixed {
	public:
		Fixed(float const &n);
		Fixed();
		Fixed(Fixed const & src);
		~Fixed();
		Fixed & operator=(Fixed const & src);

		int getRawBits() const;
		void setRawBits(int number);
		int toInt() const;
		float toFloat() const;

		// Comparisons
		bool operator<(Fixed const &comp) const;
		bool operator>(Fixed const &comp) const;
		bool operator<=(Fixed const &comp) const;
		bool operator>=(Fixed const &comp) const;
		bool operator==(Fixed const &comp) const;
		bool operator!=(Fixed const &comp) const;

		Fixed operator+(Fixed const &f) const;
		Fixed operator-(Fixed const &f) const;
		Fixed operator*(Fixed const &f) const;
		Fixed operator/(Fixed const &f) const;

		Fixed operator++();
		Fixed operator++(int i);
		Fixed operator--();
		Fixed operator--(int i);

		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed const &min(Fixed const &a, Fixed const &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static Fixed const &max(Fixed const &a, Fixed const &b);

	private:
		int m_Number;
		static const int s_Point;

	protected:

};

std::ostream &operator<<(std::ostream &o, Fixed const &f);

#endif