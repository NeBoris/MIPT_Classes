#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>

double square_root(double num) {
	if (num < 0) {
		throw std::domain_error("Number must be positive");
	}
	return sqrt(num);
}

std::string reverse_str(const char* c, int size) {
	if (!c) {
		throw std::bad_typeid();
	}
	std::string str;
	str.resize(size);
	for (int i = 0; i < size; ++i) {
		str[size - i - 1] = *(c + i);
	}

	return str;
}

class Rational {
public:
	Rational(int numerator, int denominator) :
		m_numerator(numerator), m_denominator(denominator)
	{
		if (m_denominator == 0) {
			throw std::invalid_argument("Denominator mustn't be equal to 0.");
		}
	}
		
	Rational(double a)
	{
		int b = 1;
		int N = 0;
		while (a - int(a) != 0.0 && N != 10) {
			a *= 10;
			b *= 10;
			++N;
		}
		if (a - int(a) != 0.0) {
			throw std::range_error("This number cannot be transformed to rational in this app.");
		}
		m_numerator = int(a);
		m_denominator = b;
	}

	void imagine_class_invariant_is_broken() {
		if (cos * cos + sin * sin != 1){
			throw std::logic_error("Class invariant is broken.");
		}
	}


private:
	int m_numerator;
	int m_denominator;
	double sin = 0.5;
	double cos = 0.867;
};

int main(){
	try {
		char* c = new char();
		int size;

		//1 error
		square_root(-12);

		//2 error
		Rational R1(12, 0);
		
		//3 error
		Rational R2(1.98765434567);

		//4 error
		Rational R3(4, 3);
		R3.imagine_class_invariant_is_broken();

		std::cout << "Enter the number of symbols in the string: ";
		std::cin >> size;
		std::cout << "\nEnter symbols without spaces: \n";
		for (int i = 0; i < size; ++i) {
			std::cin >> *(c + i);
		}
		std::cout << reverse_str(c, size) << std::endl;
		
		//5 error
		std::cout << reverse_str(nullptr, size);



	}
	catch (const std::invalid_argument& ia) {
		std::cerr << ia.what() << '\n';
	}
	catch (const std::domain_error& de) {
		std::cerr << de.what() << '\n';
	}
	catch (const std::range_error& re) {
		std::cerr << re.what() << '\n';
	}
	catch (const std::bad_typeid& bt) {
		std::cerr << "Bad typeid: " << bt.what() << '\n';
	}
	catch (const std::logic_error& le) {
		std::cerr << le.what() << '\n';
	}
	catch (...) {

	}

	return 0;
}