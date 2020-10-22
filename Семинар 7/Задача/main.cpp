#include <iostream>
#include <vector>
#include "List_of_figures.hpp"

//List_of_figures.hpp - объ€вление классов фигур
//figures.cpp - определение их функций
//BaseClass.hpp 
//BaseRealisation.cpp


int main() {
	std::vector<double> v1 = { 3, 4, 5 };
	std::vector<double> v2 = { 2, 3, 4, 5 };

	Shape::Finite_figure* el1 = new Shape::Ellipse(3, 4);
	Shape::Finite_figure* circ = new Shape::Circle(2);
	Shape::Finite_figure* tri2 = new Shape::Triangle(4, 2, 0.5);
	Shape::Finite_figure* par2 = new Shape::Parallelogram(4, 2, 0.5);
	Shape::Finite_figure* romb2 = new Shape::Rhombus(5, 4, 0.5);
	Shape::Finite_figure* rec1 = new Shape::Rectangle(2, 3);
	Shape::Finite_figure* rec2 = new Shape::Rectangle(2, 3, 0.5);
	Shape::Finite_figure* rec3 = new Shape::Rectangle(v1);
	Shape::Finite_figure* sq = new Shape::Square(6);

	el1->info();
	circ->info();
	tri2->info();
	par2->info();
	romb2->info();
	rec1->info();
	rec2->info();
	rec3->info();
	sq->info();
	sq->draw_graph();

	
	return 0;
}