#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

namespace CS1124{
	class Rational {
		friend std::istream& operator>>(std::istream& is, Rational& rhs);
		friend std::ostream& operator<<(std::ostream& os, const Rational& rhs);
		friend bool operator==(const Rational& lhs, const Rational& rhs);
	public:
		Rational(int num = 0, int denom = 1);
		Rational& operator+=(const Rational& rhs);
		Rational& operator++();
		Rational operator++(int);
		explicit operator bool() const;

	private:
		void normalize();

		int numerator;
		int denominator;
	};
	Rational operator+(const Rational& lhs, const Rational& rhs);
	bool operator!=(const Rational& lhs, const Rational& rhs);
	Rational& operator--(Rational& lhs);
	Rational operator--(Rational& lhs, int);
}
#endif RATIONAL_H