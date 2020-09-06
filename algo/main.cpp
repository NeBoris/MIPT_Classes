#include <iostream>

int main(){
	int x = 5, y = 9;


	x += y;
	y = x - y;
	x -= y;

	std::cout << "x = " << x << "\ny = " << y << std::endl;

	return 0;
}
