#include <iostream>
#include <string>
#include <vector>

class Capacitance {
public:

	Capacitance(double new_value, int i) : 
		value(new_value), x(i) {}

	void convert_to_sgs() {
		if (x == 1) {
			value *= c_in_2power * power;
			x = 2;
		}
	}

	void convert_to_si() {
		if (x == 2) {
			value /= c_in_2power * power;
			x = 1;
		}
	}
	friend std::ostream& operator<< (std::ostream& stream, const Capacitance& k) {
		stream << k.value << (k.x == 1 ? " Far" : " sm");
		return stream;
	}

private:
	double value;
	int x;
	static const int c_in_2power = 9;
	static const int power = 11;
};



int main() {
	double a;
	int b;

	std::cout << "Enter the capacitance and its edinitsu izmerenia (1 - Farad, 2 - sm): ";
	std::cin >> a >> b;
	
	
	Capacitance c(a, b);

	if (b == 2) {
		c.convert_to_si();
	}
	else {
		c.convert_to_sgs();
	}
	

	std::cout << c;

	return 0;
}
