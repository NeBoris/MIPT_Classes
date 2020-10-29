#pragma once
#include <iostream>

namespace use {
	class Rational {
	public:
		Rational() noexcept;
		Rational(const Rational&);
		Rational(const int& a) noexcept;
		Rational(double a);
		Rational(const int a, const int b);

		~Rational() = default;



		Rational& operator=(const Rational& a);
		Rational& operator=(Rational&& a);

		friend Rational operator+(const Rational& a, const Rational& b) noexcept;
		friend Rational operator-(const Rational& a, const Rational& b) noexcept;
		friend Rational operator*(const Rational& a, const Rational& b) noexcept;
		friend Rational operator/(const Rational& a, const Rational& b) noexcept;

		Rational operator++() noexcept;
		Rational operator--() noexcept;
		Rational operator++(int) noexcept;
		Rational operator--(int) noexcept;

		void operator+=(const Rational& other) noexcept;
		void operator-=(const Rational& other) noexcept;
		void operator/=(const Rational& other);
		void operator*=(const Rational& other) noexcept;

		operator double() const noexcept;

		friend std::ostream& operator<<(std::ostream& stream, const Rational& r) noexcept;
		friend std::istream& operator>>(std::istream& stream, Rational& r) noexcept;

		friend bool operator==(const Rational& a, const Rational& b)noexcept;
		friend bool operator!=(const Rational& a, const Rational& b) noexcept;
		friend bool operator>(const Rational& a, const Rational& b) noexcept;
		friend bool operator<(const Rational& a, const Rational& b) noexcept;
		friend bool operator>=(const Rational& a, const Rational& b) noexcept;
		friend bool operator<=(const Rational& a, const Rational& b) noexcept;

	private:
		int m_numerator;
		int m_denominator;
		void simplify();
	};
}