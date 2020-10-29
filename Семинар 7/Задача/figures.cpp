#include "List_of_figures.hpp"
#include <iomanip>
#include <iostream>
#include <utility>
#include <cmath>



namespace Shape {
	Finite_figure::Finite_figure() {
		m_fig_param_1 = 0;
		m_fig_param_2 = 0;
	}


//class Ellipse (> Finite_figure)
	Ellipse::Ellipse() = default;

// a - big poluos, b - small poluos
	Ellipse::Ellipse(int a, int b) {
		m_fig_param_1 = a;
		m_fig_param_2 = b;
	}
//main points to build particular ellipse
	void Ellipse::get_points() {
		points.push_back({ 0,0 });
		points.push_back({ 0,m_fig_param_2 });
		points.push_back({ 0,-m_fig_param_2 });
		points.push_back({ m_fig_param_1,0 });
		points.push_back({ -m_fig_param_1, 0 });
	}

	double Ellipse::perimetr() {
		if (m_fig_param_1 + m_fig_param_2 != 0) {
			double P = 4 * (area() + m_fig_param_1 - m_fig_param_1) / (m_fig_param_1 + m_fig_param_1);
			return P;
		}
		return 0;
	}

	double Ellipse::area() {
		static const double PI = 3.141592653589793;
		if (m_fig_param_1 == 0 || m_fig_param_2 == 0) {
			return 0;
		}
		return m_fig_param_1 * m_fig_param_1 * PI;
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


//Circle ( > Ellipse > Finit_figure)

	Circle::Circle(int r) {
		m_fig_param_1 = r;
		m_fig_param_2 = r;
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


//Polygon (> Finit_figure)

	Polygon::Polygon() :
		m_sides(0), m_fig_param_3(0){}

	Polygon::Polygon(const std::vector<double>& sides) :
		m_sides(sides), m_fig_param_3(0){}

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
//side and a height
	Triangle::Triangle(double a, double h) {
		m_fig_param_1 = a;
		m_fig_param_2 = h;
	}
//two sides and angel between
	Triangle::Triangle(double a, double b, double sin) {
		m_fig_param_3 = sin;
		m_sides.push_back(a);
		m_sides.push_back(b);
		
		points.push_back({ 0,0 });
		points.push_back({ m_sides[0], 0 });
		points.push_back({ m_sides[1] * sqrt(1 - m_fig_param_3 * m_fig_param_3), m_sides[1] * m_fig_param_3 });
	}
//vector with sides' sizes
	Triangle::Triangle(const std::vector<double>& sides) {
		m_sides = sides;
		m_sides.resize(3);
	}


	double Triangle::area() {
		//two sides and angel between
		if (m_fig_param_2 == 0 && m_fig_param_3 != 0 && m_sides.size() == 2) {
			return m_fig_param_3 * m_sides[0] * m_sides[1] * 0.5;
		}
		//side and a height
		else if (m_fig_param_1 != 0 && m_fig_param_2 != 0 && (m_fig_param_3 == 0 || m_sides.size() < 2)) {
			return m_fig_param_1 * m_fig_param_2 * 0.5;
		}
		//Geron
		else if (m_fig_param_2 == 0 && m_fig_param_3 == 0 && m_sides.size() == 3) {
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
		stream << std::setprecision(4);
		if (m_sides.size() == 3) {
			stream << std::left << std::setw(9) << "Perimetr: "
				<< std::right << std::setw(11) << perimetr() << std::endl;
		}
			stream << std::left << std::setw(9) << "Area: "
			<< std::right << std::setw(11) << area() << std::endl;
	}

//Quadrangle (> Polygon)
	Quadrangle::Quadrangle() = default;
	Quadrangle::Quadrangle(const std::vector<double>& sides){
		m_sides = sides;
		m_sides.resize(4);
	}

	void Quadrangle::print(std::ostream& stream) {
		stream << "Quadrangle\n";
		stream << std::setprecision(4)
			<< std::left << std::setw(9) << "Perimetr: "
			<< std::right << std::setw(11) << perimetr() << std::endl;
	}


//Parallelogram (> Quadrangle > Polygon)
	Parallelogram::Parallelogram() = default;
	Parallelogram::Parallelogram(const std::vector<double>& sides) {
		if (sides[0] == sides[2] && sides[1] == sides[3]) {
			m_sides = sides;
			m_sides.resize(4);
		}
	}
	Parallelogram::Parallelogram(double a, double b, double sin) {
		m_fig_param_3 = sin;
		for (int i = 0; i < 2; i++) {
			m_sides.push_back(a);
			m_sides.push_back(b);
		}
	}
	Parallelogram::Parallelogram(double a, double h) {
		m_fig_param_1 = a;
		m_fig_param_2 = h;
	}
	
	double Parallelogram::area() {
		if (m_fig_param_3 != 0 && m_sides.size() >= 2) {
			return m_sides[0] * m_sides[1] * m_fig_param_3;
		}
		else if (m_fig_param_3 == 0 && m_sides.empty()) {
			return m_fig_param_1 * m_fig_param_2;
		}
		return 0;
	}

	void Parallelogram::get_points() {
		if (m_fig_param_3 != 0) {
			points.push_back({ 0,0 });
			points.push_back({ m_sides[0], 0 });
			points.push_back({ m_sides[1] * sqrt(1 - m_fig_param_3 * m_fig_param_3), m_sides[1] * m_fig_param_3 });
			points.push_back({ m_sides[0] + m_sides[1] * sqrt(1 - m_fig_param_3 * m_fig_param_3), m_sides[0] + m_sides[1] * m_fig_param_3 });
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


//Rhombus (> parallelogram > Quadrangle > Polygon)
	Rhombus::Rhombus() = default;
	Rhombus::Rhombus(const std::vector<double>& sides) {
		if ((sides[0] == sides[1]) && (sides[1] == sides[2]) && (sides[2] == sides[3])) {
			m_sides = sides;
			m_sides.resize(4);
		}
	}
	Rhombus::Rhombus(double d1, double d2) {
		m_fig_param_1 = 0.5 * d1;
		m_fig_param_2 = d2;
	}
	Rhombus::Rhombus(double a, double b, double sin) {
		m_fig_param_3 = sin;
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
	

//Rectangle (> Parallelogram > Quadrangle > Polygon)
	Rectangle::Rectangle() = default;
	Rectangle::Rectangle(const std::vector<double>& sides) {
		if (sides[0] == sides[2] && sides[1] == sides[3]) {
			m_sides = sides;
			m_sides.resize(4);
		}
	}
	Rectangle::Rectangle(double a, double b) {
		for (int i = 0; i < 2; i++) {
			m_sides.push_back(a);
			m_sides.push_back(b);
		}
	}
	Rectangle::Rectangle(double d1, double d2, double sin) {
		m_fig_param_1 = d1;
		m_fig_param_2 = d2;
		m_fig_param_3 = sin;
	}
	
	double Rectangle::area() {
		if (!m_sides.empty()) {
			return m_sides[0] * m_sides[1];
		}
		else {
			return m_fig_param_1 * m_fig_param_2 * m_fig_param_3 * 0.5;
		}
	}

	void Rectangle::get_points() {
		if (!m_sides.empty()) {
			points.push_back({ 0,0 });
			points.push_back({ m_sides[0], 0 });
			points.push_back({ 0, m_sides[1] });
			points.push_back({ m_sides[0], m_sides[1] });
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

//Square (> Rectangle > Parallelogram.....)
	
	Square::Square() = default;
	Square::Square(const std::vector<double>& sides) {
		if ((sides[0] == sides[1]) && (sides[1] == sides[2]) && (sides[2] == sides[3])) {
			m_sides = sides;
			m_sides.resize(4);
		}
	}
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

