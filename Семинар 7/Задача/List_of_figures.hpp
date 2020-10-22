#pragma once
#include "FigureCount.hpp"
#include <vector>

namespace Shape {

	class Finite : public Figure_c {
	protected:
		virtual double perimetr() { return 0; };
		virtual double area() { return 0; };
		
		std::vector<std::pair<double, double>> points;
	};

	class Ellipse : public Finite {
	public:
		Ellipse();
		Ellipse(int a, int b);

	protected:
		void get_points();
		double perimetr();
		double area();

		void print(std::ostream& stream);

		double m_a;
		double m_b;
	};

	class Circle : public Ellipse {
	public:
		Circle(int r);

	protected:
		void print(std::ostream& stream);
	};

	class Polygon : public Finite {
	public:
		Polygon();
		Polygon(const std::vector<double>& sides);

	protected:
		void print(std::ostream& stream);
		double perimetr();

		std::vector<double> m_sides;
	};

	class Triangle : public Polygon {
	public:
		Triangle();
		Triangle(double a, double h);
		Triangle(double a, double b, double sin);
		Triangle(const std::vector<double>& sides);
	protected:
		double area();
		double perimetr();

		void print(std::ostream& stream);
	private:
		double m_a;
		double m_h;
		double m_sin;
	};

	class Quadrangle : public Polygon {
	public:
		Quadrangle();
		Quadrangle(const std::vector<double>& sides);

	protected:
		double perimetr();
		void print(std::ostream& stream);

		double m_d1;
		double m_d2;
		double m_sin;
	};

	class Parallelogram : public Quadrangle {
	public:
		Parallelogram();
		Parallelogram(const std::vector<double>& sides);
		Parallelogram(double a, double b, double sin);
		Parallelogram(double a, double h);
	protected:
		double area();
		void get_points();
		void print(std::ostream& stream);
	};

	class Rhombus : public Parallelogram {
	public:
		Rhombus();
		Rhombus(std::vector<double> sides);
		Rhombus(double d1, double d2);
		Rhombus(double a, double b, double sin);
	protected:
		void print(std::ostream& stream);
	};

	class Rectangle : public Parallelogram {
	public:
		Rectangle();
		Rectangle(std::vector<double> sides);
		Rectangle(double a, double b);
		Rectangle(double d1, double d2, double sin);
	protected:
		void get_points();
		void print(std::ostream& stream);
	};

	class Square : public Rectangle {
	public:
		Square();
		Square(double a);
		//void draw_graph();
	protected:
		void print(std::ostream& stream);
	};
}