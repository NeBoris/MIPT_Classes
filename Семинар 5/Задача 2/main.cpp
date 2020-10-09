#include <iostream>
#include <string>
#include <vector>

static int c_in_2power = 9;
static int power = 11;

enum class ed_izm {
	sm,
	Far
};

class Capacitance {
public:

	Capacitance(double new_value, int i) : 
		value(new_value), x(static_cast< ed_izm > (i) ) {}

	void convert_to_sgs() {
		value *= c_in_2power * power;
		x = static_cast<ed_izm> (2);
	}

	void convert_to_si() {
		value /= c_in_2power * power;
		x = static_cast<ed_izm> (1);
	}
	friend std::ostream& operator<< (std::ostream& stream, const Capacitance& k) {
		stream << k.value << (k.x == static_cast<ed_izm> (1) ? " Far" : " sm");
		return stream;
	}

private:
	double value;
	ed_izm x;
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
