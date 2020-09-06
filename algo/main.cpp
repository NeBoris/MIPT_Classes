#include <iostream>

int main(){
	int x = 5, y = 9;


	x += 10*y;
	y = x % 10;
	x /= 10;

	std::cout << "x = " << x << "\ny = " << y << std::endl;

	return 0;
}
