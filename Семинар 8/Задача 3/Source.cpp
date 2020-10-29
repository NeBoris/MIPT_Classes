#include "Rational.hpp"
#include <iostream>

namespace use {
	Rational::operator double() const noexcept{
		return (double)m_numerator / (double)m_denominator;
	}
	Rational::Rational() noexcept :
		m_numerator(0), m_denominator(1) {}
	Rational::Rational(const Rational& a) = default;
	Rational::Rational(const int& a) noexcept :
		m_numerator(a), m_denominator(1) {}
	Rational::Rational(double a)
	{
		int b = 1;
		int N = 0;
		while (a - int(a) != 0.0 && N != 10) {
			a *= 10;
			b *= 10;
			++N;
		}
		if (a - int(a) != 0.0) {
			throw std::range_error("This number cannot be transformed to rational in this app.");
		}
		m_numerator = int(a);
		m_denominator = b;
		simplify();
	}
	Rational::Rational(const int a, const int b) {
		if (b == 0) {
			throw std::invalid_argument("Denominator mustn't be 0");
		}

		if ((b < 0 && a < 0) || (b < 0 && a > 0)) {
			m_denominator = -b;
			m_numerator = -a;
		}
		else {
			m_denominator = b;
			m_numerator = a;
		}
		simplify();
	}


	void Rational::simplify() {
		std::size_t a = (this->m_numerator > 0 ? this->m_numerator : -this->m_numerator);
		std::size_t b = this->m_denominator;
		while (b) {
			a %= b;
			std::swap(a, b);
		}

		if(m_numerator != 0)
			m_numerator /= a;
		m_denominator /= a;

	}

	Rational& Rational::operator=(const Rational& a) = default;
	Rational& Rational::operator=(Rational&& a) = default;

	Rational operator+(const Rational& a, const Rational& b) noexcept{
		Rational result(a);
		result += b;
		result.simplify();
		return result;
	}
	Rational operator-(const Rational& a, const Rational& b) noexcept {
		Rational result(a);
		result -= b;
		result.simplify();
		return result;
	}
	Rational operator*(const Rational& a, const Rational& b) noexcept {
		Rational result(a);
		result *= b;
		result.simplify();
		return result;
	}
	Rational operator/(const Rational& a, const Rational& b) noexcept {
		Rational result(a);
		result /= b;
		result.simplify();
		return result;
	}

	// I thought for rational numbers the operation of increasing or decreasing by one is useless, so I will make it multiply or divide the number by 10

	Rational Rational::operator++() noexcept {
		this->m_numerator += this->m_denominator;
		simplify();
		return *this;
	}
	Rational Rational::operator--() noexcept {
		this->m_numerator -= this->m_denominator;
		simplify();
		return *this;
	}
	Rational Rational::operator++(int) noexcept {
		Rational temp(this->m_numerator + this->m_denominator, this->m_denominator);
		return temp;
	}
	Rational Rational::operator--(int) noexcept {
		Rational temp(this->m_numerator - this->m_denominator, this->m_denominator);
		return temp;
	}

	void Rational::operator+=(const Rational& a) noexcept {
		*this = Rational(m_numerator * a.m_denominator + a.m_numerator * m_denominator, m_denominator * a.m_denominator);
	}
	void Rational::operator-=(const Rational& a) noexcept {
		*this = Rational(m_numerator * a.m_denominator - a.m_numerator * m_denominator, m_denominator * a.m_denominator);
	}
	void Rational::operator/=(const Rational& a) {
		if (a.m_numerator == 0)
			throw std::domain_error("Division by zero!");
		*this = Rational(m_numerator * a.m_denominator, m_denominator * a.m_numerator);
	}
	void Rational::operator*=(const Rational& a) noexcept {
		*this = Rational(m_numerator * a.m_numerator, m_denominator * a.m_denominator);
	}

	std::ostream& operator<<(std::ostream& stream, const Rational& r) noexcept {
		if (r.m_denominator == 1) {
			stream << r.m_numerator;
		}
		else {
			stream << r.m_numerator << " / " << r.m_denominator;
		}
		return stream;
	}
	std::istream& operator>>(std::istream& stream, Rational& r) noexcept {
		std::int_least32_t numerator;
		std::int_least32_t denominator;

		stream >> numerator;
		if (stream.peek() == '/' || stream.peek() == ':') {
			stream.ignore(1);
			stream >> denominator;
			r = Rational(numerator, denominator);
		}
		else {
			std::cerr << ("Invalid value.");
		}

		return stream;
	}


	bool operator==(const Rational& lhs, const Rational& rhs) noexcept {
		return lhs.m_numerator == rhs.m_numerator && lhs.m_denominator == rhs.m_denominator;
	}
	bool operator!=(const Rational& lhs, const Rational& rhs) noexcept {
		return lhs.m_numerator != rhs.m_numerator || lhs.m_denominator != rhs.m_denominator;
	}
	bool operator>(const Rational& lhs, const Rational& rhs) noexcept {
		return lhs.m_numerator * rhs.m_denominator > rhs.m_numerator * lhs.m_denominator;
	}
	bool operator<(const Rational& lhs, const Rational& rhs) noexcept {
		return lhs.m_numerator * rhs.m_denominator < rhs.m_numerator* lhs.m_denominator;
	}
	bool operator>=(const Rational& lhs, const Rational& rhs) noexcept {
		return lhs.m_numerator * rhs.m_denominator >= rhs.m_numerator * lhs.m_denominator;
	}
	bool operator<=(const Rational& lhs, const Rational& rhs) noexcept {
		return lhs.m_numerator * rhs.m_denominator <= rhs.m_numerator * lhs.m_denominator;
	}
}