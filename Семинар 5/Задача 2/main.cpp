#include <iostream>
#include <string>
#include <vector>

static int c = 3;
static int power = 10;

enum class ed_izm {
	sm,
	Far
};

class capacitance {
public:

	capacitance(double new_value, int i) : 
		value(new_value), x(static_cast< ed_izm > (i) ) {}

	void convert_to_sgs() {
		value *= pow(c, 2) * pow(10, power * 2 - 9);
		x = static_cast<ed_izm> (2);
	}

	void convert_to_si() {
		value /= pow(c, 2) * pow(10, power * 2 - 9);
		x = static_cast<ed_izm> (1);
	}
	friend std::ostream& operator<< (std::ostream& stream, const capacitance& k) {
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
	
	
	capacitance c(a, b);

	if (b == 2) {
		c.convert_to_si();
	}
	else {
		c.convert_to_sgs();
	}
	

	std::cout << c;

	return 0;
}