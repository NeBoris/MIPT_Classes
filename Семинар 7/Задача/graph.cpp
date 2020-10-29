#include "List_of_figures.hpp"
#include <iostream>
#include <iomanip>
#include <vector>

namespace Shape {
	bool find(std::vector<std::pair<double, double>> v, const std::pair<double, double>& g) {
		for (const auto& c : v) {
			if (c == g) {
				return true;
			}
		}
		return false;
	}

	void Rectangle::draw_graph() {
		for (int i = 40; i >= 0; --i) {
			std::cout << std::setw(40);
			for (int j = 0; j < 41; ++j) {
				if (i == 20 && j != 20) {
					if (find(points, { j - 20, i - 20 })) {
						std::cout << 0;
					}
					else {
						std::cout << "_";
					}
				}else if (j == 20) {
					if (find(points, { j - 20, i - 20 })) {
						std::cout << 0;
					}
					else {
						std::cout << "|";
					}
				}
				else {
					if (find(points, { j - 20, i - 20} )) {
						std::cout << 0;
					}
					else {
						std::cout << ".";
					}
				}
			}
			std::cout << std::endl;
		}
	}
}