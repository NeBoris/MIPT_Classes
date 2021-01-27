#include <iostream>
#include <cmath>
#include <string>
#include <exception>
#include <stdexcept>
#include "complex.hpp"

namespace Compl
{
	////////////////////////////////////////////////////////////////////////////////////////////////

	std::ostream& operator<<(std::ostream& stream, const Complex& C) 
	{
		stream << C.m_re << (C.m_im < 0 ? " - i" : " + i") << fabs(C.m_im);
		return stream;
	}

	std::istream& operator>>(std::istream& stream, Complex& C)
	{
		bool flag = true;
		stream >> C.m_re;
	
		do{
			if (stream.peek() == '-')
			{
				flag = false;
			}
			else if (stream.peek() == '\n')
			{
				return stream;
			}
			stream.ignore(1);
		} while (stream.peek() != 'i' && stream.peek() != 'j');
		stream.ignore(1);


		stream >> C.m_im;
			
		if (!flag)
			C.m_im *= -1;

		return stream;
	}

	////////////////////////////////////////////////////////////////////////////////


	Complex Complex::sopr() const noexcept
	{
		Complex temp(this->m_re, -(this->m_im));
		return temp;
	}

	double Complex::abs() const noexcept
	{
		return sqrt((this->m_re * this->m_re) + (this->m_im * this->m_im));
	}


	////////////////////////////////////////////////////////////////////////////////

	Complex& Complex::operator+=(const Complex& other) noexcept
	{
		this->m_re += other.m_re;
		this->m_im += other.m_im;

		return *this;
	}
	Complex& Complex::operator-=(const Complex& other) noexcept
	{
		this->m_re -= other.m_re;
		this->m_im -= other.m_im;

		return *this;
	}
	Complex& Complex::operator*=(const Complex& other) noexcept
	{
		*this = Complex(this->m_re * other.m_re - this->m_im * other.m_im, this->m_re * other.m_im + this->m_im * other.m_re);

		return *this;
	}
	Complex& Complex::operator/=(const Complex& other) 
	{
		if ((other.m_re * other.m_re + other.m_im * other.m_im) == 0.0)
		{
			throw std::invalid_argument("Denominator mustn't be zero.");
		}

		double new_re = (this->m_re * other.m_re + this->m_im * other.m_im) / (other.m_re * other.m_re + other.m_im * other.m_im);
		double new_im = (this->m_im * other.m_re - this->m_re * other.m_im) / (other.m_re * other.m_re + other.m_im * other.m_im);


		*this = Complex(new_re, new_im);

		return *this;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////

	bool operator==(const Complex& lhs, const Complex& rhs)
	{
		return (lhs.m_re == rhs.m_re) && (lhs.m_im == rhs.m_im);
	}
	bool operator!=(const Complex& lhs, const Complex& rhs) 
	{
		return !(lhs == rhs);
	}

	////////////////////////////////////////////////////////////////////////////////////////////////


	Complex operator+(const Complex& lhs, const Complex& rhs)  
	{
		Complex temp = lhs;

		return temp += rhs;
	}
	Complex operator-(const Complex& lhs, const Complex& rhs) 
	{
		Complex temp = lhs;

		return temp -= rhs;
	}
	Complex operator*(const Complex& lhs, const Complex& rhs) 
	{
		Complex temp = lhs;

		return temp *= rhs;
	}
	Complex operator/(const Complex& lhs, const Complex& rhs) 
	{
		Complex temp = lhs;

		return temp /= rhs;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////

}