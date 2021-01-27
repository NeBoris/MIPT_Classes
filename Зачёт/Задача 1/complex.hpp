#pragma once

#include <iostream>

namespace Compl
{
	class Complex
	{
	public:

		Complex() :
			m_re(0.0), m_im(0.0)
		{}

		Complex(double re, double im = 0.0) noexcept :
			m_re(re), m_im(im)
		{}

		~Complex() noexcept = default;


	public:

		Complex sopr() const noexcept;

		double abs() const noexcept;

	public:

		auto Re()  const noexcept
		{
			return m_re;
		}

		auto Im()  const noexcept
		{
			return m_im;
		}

	public:

		friend std::ostream& operator<<(std::ostream& stream, const Complex& C);
		friend std::istream& operator>>(std::istream& stream, Complex& C);

	public:

		Complex& operator+=(const Complex& other) noexcept;
		Complex& operator-=(const Complex& other) noexcept;
		Complex& operator*=(const Complex& other) noexcept;
		Complex& operator/=(const Complex& other);


	public:

		friend bool operator==(const Complex& lhs, const Complex& rhs);
		friend bool operator!=(const Complex& lhs, const Complex& rhs);

	private:

		double m_re;
		double m_im;
	};

	Complex operator+(const Complex& lhs, const Complex& rhs);
	Complex operator-(const Complex& lhs, const Complex& rhs);
	Complex operator*(const Complex& lhs, const Complex& rhs);
	Complex operator/(const Complex& lhs, const Complex& rhs);

}