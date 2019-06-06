#ifndef		FIXED_HPP
# define	FIXED_HPP



class Fixed {
	public:
		Fixed();
		Fixed(Fixed const & src);
		~Fixed();
		Fixed & operator=(Fixed const & src);

		int getRawBits() const;
		void setRawBits(int number);
	private:
		int m_Number;
		static const int s_Point;

	protected:

};

#endif