#pragma once
#include <iostream>

class Figure_c {
public:
	void info();
	//virtual void draw_graph() {};
protected:
	virtual void print(std::ostream& stream) = 0;
	virtual void get_points() {};
};

