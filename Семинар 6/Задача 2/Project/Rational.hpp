#pragma once
#include <iostream>

namespace use {
	class Rational {
	public:
		Rational();
		Rational(const Rational&);
		Rational(const int& a);
		Rational(double a);
		Rational(const int a, const int b);

		~Rational() = default;

		

		Rational& operator=(const Rational& a);
		Rational& operator=(Rational&& a);

		friend Rational operator+(const Rational& a, const Rational& b);
		friend Rational operator-(const Rational& a, const Rational& b);
		friend Rational operator*(const Rational& a, const Rational& b);
		friend Rational operator/(const Rational& a, const Rational& b);

		Rational& operator++();
		Rational& operator--();
		Rational& operator++(int);
		Rational& operator--(int);

		void operator+=(const Rational& other);
		void operator-=(const Rational& other);
		void operator/=(const Rational& other);
		void operator*=(const Rational& other);

		operator double() const;

		friend std::ostream& operator<<(std::ostream& stream, const Rational& r);
		friend std::istream& operator>>(std::istream& stream, Rational& r);

		friend bool operator==(const Rational& a, const Rational& b);
		friend bool operator!=(const Rational& a, const Rational& b);
		friend bool operator>(const Rational& a, const Rational& b);
		friend bool operator<(const Rational& a, const Rational& b);
		friend bool operator>=(const Rational& a, const Rational& b);
		friend bool operator<=(const Rational& a, const Rational& b);

	private:
		int m_numerator;
		int m_denominator;
		void simplify();
	};
}