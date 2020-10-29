#pragma once
#include "BaseClass.hpp"
#include <vector>

namespace Shape {

	class Finite_figure : public Figure_c {
	protected:
		Finite_figure();	
		virtual double perimetr() { return 0; };
		virtual double area() { return 0; };

		//points for graph
		std::vector<std::pair<double, double>> points;
		
		double m_fig_param_1;
		double m_fig_param_2;
	};

	class Ellipse : public Finite_figure {
	public:
		Ellipse();
		Ellipse(int a, int b);

	protected:
		void get_points();
		double perimetr();
		double area();

		void print(std::ostream& stream);

	};

	class Circle : public Ellipse {
	public:
		Circle(int r);

	protected:
		void print(std::ostream& stream);
	};

	class Polygon : public Finite_figure {
	public:
		Polygon();
		Polygon(const std::vector<double>& sides);

	protected:
		void print(std::ostream& stream);
		double perimetr();

		double m_fig_param_3;

//to save sides sizes
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

		void print(std::ostream& stream);
	};

	class Quadrangle : public Polygon {
	public:
		Quadrangle();
		Quadrangle(const std::vector<double>& sides);

	protected:
		void print(std::ostream& stream);
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
		Rhombus(const std::vector<double>& sides);
		Rhombus(double d1, double d2);
		Rhombus(double a, double b, double sin);
	protected:
		void print(std::ostream& stream);
	};

	class Rectangle : public Parallelogram {
	public:
		Rectangle();
		Rectangle(const std::vector<double>& sides);
		Rectangle(double a, double b);
		Rectangle(double d1, double d2, double sin);
	protected:
		void draw_graph();
		void get_points();
		double area();
		void print(std::ostream& stream);
	};

	class Square : public Rectangle {
	public:
		Square();
		Square(const std::vector<double>& sides);
		Square(double a);
	protected:
		void print(std::ostream& stream);
	};
}