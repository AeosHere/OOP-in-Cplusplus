#include "Rational.h"
#include "gcd.h"

//using namespace CS1124;
using namespace std;

namespace CS1124 {
	Rational::Rational(int num, int denom) : numerator(num), denominator(denom) {
		if (denominator == 0) {
			cerr << "Denominator cannot be 0" << endl;
			exit(1);
		}
		normalize();
	}

	Rational& Rational::operator+=(const Rational& rhs) {
		numerator = numerator * rhs.denominator + rhs.numerator * denominator;
		denominator = denominator * rhs.denominator;
		normalize();
		return *this;
	}

	Rational& Rational::operator++() {
		numerator += denominator;
		return *this;
	}

	Rational Rational::operator++(int) {
		Rational old = *this;
		numerator += denominator;
		return old;
	}

	Rational::operator bool() const {
		return numerator != 0;
	}

	void Rational::normalize() {
		int gcd = greatestCommonDivisor(numerator, denominator);
		numerator /= gcd;
		denominator /= gcd;
	}

	istream& operator>>(istream& is, Rational& rhs) {
		char slash;
		is >> rhs.numerator >> slash >> rhs.denominator;
		rhs.normalize();
		return is;
	}

	ostream& operator<<(ostream& os, const Rational& rhs) {
		os << rhs.numerator << "/" << rhs.denominator;
		return os;
	}

	bool operator==(const Rational& lhs, const Rational& rhs) {
		return lhs.numerator == rhs.numerator && lhs.denominator == rhs.denominator;
	}

	Rational operator+(const Rational& lhs, const Rational& rhs) {
		Rational result = lhs;
		result += rhs;
		return result;
	}

	bool operator!=(const Rational& lhs, const Rational& rhs) {
		return !(lhs == rhs);
	}

	Rational& operator--(Rational& lhs) {
		Rational negativeOne = -1;
		lhs += negativeOne;
		return lhs;
	}

	Rational operator--(Rational& lhs, int) {
		Rational negativeOne = -1;
		Rational old = lhs;
		lhs += negativeOne;
		return old;
	}
}


