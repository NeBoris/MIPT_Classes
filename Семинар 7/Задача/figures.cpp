#include "List_of_figures.hpp"
#include <iomanip>
#include <iostream>
#include <utility>
#include <cmath>



namespace Shape {
	
	Ellipse::Ellipse() :
		m_a(0), m_b(0){}

	Ellipse::Ellipse(int a, int b) :
		m_a(a), m_b(b){}

	void Ellipse::get_points() {
		points.push_back({ 0,0 });
		points.push_back({ 0,m_b });
		points.push_back({ 0,-m_b });
		points.push_back({ m_a,0 });
		points.push_back({ 0,-m_a });
	}

	double Ellipse::perimetr() {
		if (m_a + m_b != 0) {
			double P = 4 * (area() + m_a - m_b) / (m_a + m_b);
			return P;
		}
		return 0;
	}

	double Ellipse::area() {
		static const double PI = 3.141592653589793;
		if (m_a == 0 || m_b == 0) {
			return 0;
		}
		return m_a * m_b * PI;
	}

	void Ellipse::print(std::ostream& stream) {
		stream << "Ellipse\n"
			<< "This ellipse include these main points: ";
		get_points();
		for (const auto& c : points) {
			stream << "(" << std::get<0>(c) << "; " << std::get<1>(c) << "), ";
		}
		stream << std::endl;
		stream  << std::setprecision(4)
			<< std::left << std::setw(9) << "Perimetr: "
			<< std::right << std::setw(11) << perimetr() << std::endl
			<< std::left << std::setw(9) << "Area: "
			<< std::right << std::setw(11) << area() << std::endl;
		
	}




	Circle::Circle(int r) {
		m_a = r;
		m_b = r;
	}

	void Circle::print(std::ostream& stream) {
		stream << "Circle\n"
			<< "This circle include these main points: ";
		get_points();
		for (const auto& c : points) {
			stream << "(" << std::get<0>(c) << "; " << std::get<1>(c) << "), ";
		}
		stream << std::endl;
		stream <<  std::setprecision(4)
			<< std::left << std::setw(9) << "Perimetr: "
			<< std::right << std::setw(11) << perimetr() << std::endl
			<< std::left << std::setw(9) << "Area: "
			<< std::right << std::setw(11) << area() << std::endl;
	}




	Polygon::Polygon() :
		m_sides(0){}

	Polygon::Polygon(const std::vector<double>& sides) :
		m_sides(sides){}

	double Polygon::perimetr() {
		double P = 0;
		for (const auto c : m_sides) {
			P += c;
		}

		return P;
	}

	void Polygon::print(std::ostream& stream) {
		stream << "Polygon\n";
		stream << std::setprecision(4)
			<< std::left << std::setw(9) << "Perimetr: "
			<< std::right << std::setw(11) << perimetr() << std::endl;
	}



	Triangle::Triangle() = default;

	Triangle::Triangle(double a, double h) :
		m_a(a), m_h(h), m_sin(0){}

	Triangle::Triangle(double a, double b, double sin) :
		m_sin(sin), m_a(0), m_h(0) {
		m_sides.push_back(a);
		m_sides.push_back(b);
		
		points.push_back({ 0,0 });
		points.push_back({ m_sides[0], 0 });
		points.push_back({ m_sides[1] * sqrt(1 - m_sin * m_sin), m_sides[1] * m_sin });
	}
	Triangle::Triangle(const std::vector<double>& sides) {
		m_sides = sides;
	}

	double Triangle::perimetr() {
		if (m_sides.size() != 3) {
			return 0;
		}
		double P = 0;
		for (const auto c : m_sides) {
			P += c;
		}

		return P;
	}

	double Triangle::area() {
		if (m_h == 0 && m_sin != 0 && m_sides.size() == 2) {
			return m_sin * m_sides[0] * m_sides[1] * 0.5;
		}
		else if (m_a != 0 && m_h != 0 && m_sin == 0) {
			return m_a * m_h * 0.5;
		}
		else if (m_h == 0 && m_sin == 0 && m_sides.size() == 3) {
			double p2 = perimetr() / 2;
			return sqrt( p2 * (p2 - m_sides[0]) * (p2 - m_sides[1]) * (p2 - m_sides[2]) );
		}
		return 0;
	}


	void Triangle::print(std::ostream& stream) {
		stream << "Triangle\n";
		if (!points.empty()) {
			stream << "This triangle include these main points: ";
			for (const auto& c : points) {
				stream << "(" << std::get<0>(c) << "; " << std::get<1>(c) << "), ";
			}
			stream << std::endl;
		}
		stream << std::setprecision(4)
			<< std::left << std::setw(9) << "Perimetr: "
			<< std::right << std::setw(11) << perimetr() << std::endl
			<< std::left << std::setw(9) << "Area: "
			<< std::right << std::setw(11) << area() << std::endl;
	}

	
	Quadrangle::Quadrangle() :
		m_d1(0), m_d2(0), m_sin(0){}
	Quadrangle::Quadrangle(const std::vector<double>& sides) :
		m_d1(0), m_d2(0), m_sin(0) {
		m_sides = sides;
	}

	double Quadrangle::perimetr() {
		if (m_sides.size() != 4) {
			return 0;
		}
		double P = 0;
		for (const auto c : m_sides) {
			P += c;
		}

		return P;
	}

	void Quadrangle::print(std::ostream& stream) {
		stream << "Quadrangle\n";
		stream << std::setprecision(4)
			<< std::left << std::setw(9) << "Perimetr: "
			<< std::right << std::setw(11) << perimetr() << std::endl;
	}


	
	Parallelogram::Parallelogram() = default;
	Parallelogram::Parallelogram(const std::vector<double>& sides) {
		m_sides = sides;
	}
	Parallelogram::Parallelogram(double a, double b, double sin) {
		m_sin = sin;
		for (int i = 0; i < 2; i++) {
			m_sides.push_back(a);
			m_sides.push_back(b);
		}
	}
	Parallelogram::Parallelogram(double a, double h) {
		m_d1 = a;
		m_d2 = h;
	}
	
	double Parallelogram::area() {
		if (m_sin == 0 && !m_sides.empty()) {
			return m_sides[0] * m_sides[1];
		}
		else if (m_sin == 0 && m_sides.empty()) {
			return m_d1 * m_d2;
		}
		else if (m_sin != 0 && m_sides.empty()) {
			return m_d1 * m_d2 * m_sin;
		}
		else {
			return m_sides[0] * m_sides[1] * m_sin;
		}
	}

	void Parallelogram::get_points() {
		if (m_sin != 0) {
			points.push_back({ 0,0 });
			points.push_back({ m_sides[0], 0 });
			points.push_back({ m_sides[1] * sqrt(1 - m_sin * m_sin), m_sides[1] * m_sin });
			points.push_back({ m_sides[0] + m_sides[1] * sqrt(1 - m_sin * m_sin), m_sides[0] + m_sides[1] * m_sin });
		}

	}

	void Parallelogram::print(std::ostream& stream) {
		stream << "Parallelogram\n";
		get_points();
		if (!points.empty()) {
			stream << "This parallelogram include these main points: ";
			for (const auto& c : points) {
				stream << "(" << std::get<0>(c) << "; " << std::get<1>(c) << "), ";
			}
			stream << std::endl;
		}
		stream << std::setprecision(4)
			<< std::left << std::setw(9) << "Perimetr: "
			<< std::right << std::setw(11) << perimetr() << std::endl
			<< std::left << std::setw(9) << "Area: "
			<< std::right << std::setw(11) << area() << std::endl;
	}


	
	Rhombus::Rhombus() = default;
	Rhombus::Rhombus(std::vector<double> sides) {
		m_sides = sides;
	}
	Rhombus::Rhombus(double d1, double d2) {
		m_d1 = 0.5 * d1;
		m_d2 = d2;
	}
	Rhombus::Rhombus(double a, double b, double sin) {
		m_sin = sin;
		for (int i = 0; i < 2; i++) {
			m_sides.push_back(a);
			m_sides.push_back(b);
		}
	}

	void Rhombus::print(std::ostream& stream) {
		stream << "Rhombus\n";
		get_points();
		if (!points.empty()) {
			stream << "This rhombus include these main points: ";
			for (const auto& c : points) {
				stream << "(" << std::get<0>(c) << "; " << std::get<1>(c) << "), ";
			}
			stream << std::endl;
		}
		stream << std::setprecision(4)
			<< std::left << std::setw(9) << "Perimetr: "
			<< std::right << std::setw(11) << perimetr() << std::endl
			<< std::left << std::setw(9) << "Area: "
			<< std::right << std::setw(11) << area() << std::endl;
	}
	


	Rectangle::Rectangle() = default;
	Rectangle::Rectangle(std::vector<double> sides) {
		m_sides = sides;
	}
	Rectangle::Rectangle(double a, double b) {
		for (int i = 0; i < 2; i++) {
			m_sides.push_back(a);
			m_sides.push_back(b);
		}
	}
	Rectangle::Rectangle(double d1, double d2, double sin) {
		m_d1 = 0.5 * d1;
		m_d2 = d2;
		m_sin = sin;
	}
	
	void Rectangle::get_points() {
		if (!m_sides.empty()) {
			points.push_back({ 0,0 });
			points.push_back({ m_sides[0], 0 });
			points.push_back({ 0, m_sides[1] });
			points.push_back({ m_sides[0], m_sides[1] });
		}
		else if(m_sin == 0){
			points.push_back({ 0,0 });
			points.push_back({ m_d1, 0 });
			points.push_back({ 0, m_d2 });
			points.push_back({ m_d1, m_d2 });
		}
	}

	void Rectangle::print(std::ostream& stream) {
		stream << "Rectangle\n";
		get_points();
		if (!points.empty()) {
			stream << "This rectangle include these main points: ";
			for (const auto& c : points) {
				stream << "(" << std::get<0>(c) << "; " << std::get<1>(c) << "), ";
			}
			stream << std::endl;
		}
		stream << std::setprecision(4)
			<< std::left << std::setw(9) << "Perimetr: "
			<< std::right << std::setw(11) << perimetr() << std::endl
			<< std::left << std::setw(9) << "Area: "
			<< std::right << std::setw(11) << area() << std::endl;
	}


	
	Square::Square() = default;
	Square::Square(double a) {
		for (int i = 0; i < 2; i++) {
			m_sides.push_back(a);
			m_sides.push_back(a);
		}
	}
	
	void Square::print(std::ostream& stream) {
		stream << "Square\n";
		get_points();
		if (!points.empty()) {
			stream << "This square include these main points: ";
			for (const auto& c : points) {
				stream << "(" << std::get<0>(c) << "; " << std::get<1>(c) << "), ";
			}
			stream << std::endl;
		}
		stream << std::setprecision(4)
			<< std::left << std::setw(9) << "Perimetr: "
			<< std::right << std::setw(11) << perimetr() << std::endl
			<< std::left << std::setw(9) << "Area: "
			<< std::right << std::setw(11) << area() << std::endl;
	}
	
}

