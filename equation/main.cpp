
#include <iostream>
#include <iomanip>
#include <cmath>

int main(){
	double a, b, c, D, x1, x2;
	std::string s = "";

	std::cout << "Введите коэффициенты квадратног уравнения (a,b,c): ";

	std::cin >> a >> b >> c;

	if(a == 0){
		if(b == 0){
			s = "Решений нет";
		}else{
			x1 = x2 = -c/b;
		}
	}else if(b == 0){
		if(-c/a < 0){
			s = "Действительных корней нет";
		}else{
			x1 = -sqrt(-c/a);
			x2 = sqrt(-c/a);
		}
	}else{
		D = b*b - 4*a*c;

		if(D < 0){
			s = "Решений нет";
		}else{
			x1 = (-b*b - sqrt(D))/(2*a);
			x2 = (-b*b + sqrt(D))/(2*a);
		}

	}

	if(s.empty()){
		std::cout << "x1 = " << x1 << "\nx2 = " << x2 << std::endl;
	}else{
		std::cout << s;
	}


	return 0;
}

