#include "Rational.hpp"
#include <iostream>

namespace use {
	Rational::operator double() const {
		return (double)m_numerator / (double)m_denominator;
	}
	Rational::Rational():
		m_numerator(0), m_denominator(1), m_doub(0){}
	Rational::Rational(const Rational& a) :
		m_numerator(a.m_numerator), m_denominator(a.m_denominator), m_doub(a.m_doub){}
	Rational::Rational(const int& a) :
		m_numerator(a), m_denominator(1), m_doub(a){}
	Rational::Rational(double a) 
	{
		int b = 1;
		int N = 0;
		while (a - int(a) != 0.0 || N != 7) {
			a *= 10;
			b *= 10;
			++N;
		}
		m_numerator = int(a);
		m_denominator = b;
		simplify();
		m_doub = double(*this);
	}
	Rational::Rational(const int& a, const int& b) {
		if (b == 0) {
			return;
		}

		if ( (b < 0 && a < 0) || (b < 0 && a > 0) ) {
			m_denominator = -b;
			m_numerator = -a;
		}
		else {
			m_denominator = b;
			m_numerator = a;
		}
		simplify();
		m_doub = double(*this);
	}


	void Rational::simplify() {
		std::size_t a = (this->m_numerator > 0 ? this->m_numerator : -this->m_numerator);
		std::size_t b = this->m_denominator;
		while (b) {
			a %= b;
			std::swap(a, b);
		}

		m_numerator /= a;
		m_denominator /= a;

	}

	Rational& Rational::operator=(const Rational& a) {
		m_numerator = a.m_numerator;
		m_denominator = a.m_denominator;
		m_doub = double(*this);
		return *this;
	}
	Rational& Rational::operator=(Rational&& a) = default;

	Rational operator+(const Rational & a, const Rational & b) {
		Rational result(a);
		result += b;
		return result;
	}
	Rational operator-(const Rational & a, const Rational & b) {
		Rational result(a);
		result -= b;
		return result;
	}
	Rational operator*(const Rational & a, const Rational & b) {
		Rational result(a);
		result *= b;
		return result;
	}
	Rational operator/(const Rational& a, const Rational& b) {
		Rational result(a);
		result /= b;
		return result;
	}

	// I thought for rational numbers the operation of increasing or decreasing by one is useless, so I will make it multiply or divide the number by 10

	Rational& Rational::operator++() {
		this->m_numerator *= 10;
		this->m_doub = double(*this);
		return *this;
	}
	Rational& Rational::operator--() {
		this->m_denominator *= 10;
		this->m_doub = double(*this);
		return *this;
	}
	Rational&& Rational::operator++(int) {
		Rational temp(this->m_numerator, this->m_denominator);
		this->m_numerator *= 10;
		this->m_doub = double(*this);
		return std::move(temp);
	}
	Rational&& Rational::operator--(int) {
		Rational temp(this->m_numerator, this->m_denominator);
		this->m_denominator *= 10;
		this->m_doub = double(*this);
		return std::move(temp);
	}

	void Rational::operator+=(const Rational& a) {
		*this = Rational(m_numerator*a.m_denominator + a.m_numerator*m_denominator, m_denominator * a.m_denominator);
		m_doub = double(*this);
	}
	void Rational::operator-=(const Rational& a) {
		*this = Rational(m_numerator * a.m_denominator - a.m_numerator * m_denominator, m_denominator * a.m_denominator);
		m_doub = double(*this);
	}
	void Rational::operator/=(const Rational& a) {
		*this = Rational(m_numerator * a.m_denominator, m_denominator * a.m_numerator);
		m_doub = double(*this);
	}
	void Rational::operator*=(const Rational& a) {
		*this = Rational(m_numerator * a.m_numerator, m_denominator * a.m_denominator);
		m_doub = double(*this);
	}

	double Rational::get_double() const {
		return m_doub;
	}
	double get_double(Rational&& a) {
		return a.m_doub;
	}

	

	std::ostream& operator<<(std::ostream& stream, const Rational& r) {
		stream << r.m_numerator << " / " << r.m_denominator;
		return stream;
	}
	std::istream& operator>>(std::istream& stream, Rational& r) {
		std::int_least32_t numerator;
		std::int_least32_t denominator;

		stream >> numerator;
		if(stream.peek() == '/' || stream.peek() == ':'){
			stream.ignore(1);
			stream >> denominator;
			r = Rational(numerator, denominator);
		}
		else {
			std::cerr << ("Invalid value.");
		}

		return stream;
	}

	
	bool operator==(const Rational& lhs, const Rational& rhs){
		return lhs.m_numerator == rhs.m_numerator && lhs.m_denominator == rhs.m_denominator;
	}
	bool operator>(const Rational& lhs, const Rational& rhs) {
		return lhs.m_numerator*rhs.m_denominator > rhs.m_numerator*lhs.m_denominator;
	}
	bool operator<(const Rational& lhs, const Rational& rhs) {
		return lhs.m_numerator * rhs.m_denominator < rhs.m_numerator * lhs.m_denominator;
	}
	bool operator>=(const Rational& lhs, const Rational& rhs) {
		return lhs.m_numerator * rhs.m_denominator >= rhs.m_numerator * lhs.m_denominator;
	}
	bool operator<=(const Rational& lhs, const Rational& rhs) {
		return lhs.m_numerator * rhs.m_denominator <= rhs.m_numerator * lhs.m_denominator;
	}
}