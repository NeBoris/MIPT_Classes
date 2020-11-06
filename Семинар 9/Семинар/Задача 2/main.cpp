#include <iostream>
#include <vector>
#include <algorithm>
#include "container.hpp"

int main() {
	std::vector<int> v = { 1,2,3,234,5,124,7 };
	std::vector<int> v2 = { 1123,2124,124125,4125,5124,6,7 };

	not_std::my_container<int> mC(v);
	not_std::my_container<int> mC2(v2);

	
	std::cout << mC << "\n" << mC2;

	std::sort(mC.begin(), mC.end());
	std::sort(mC2.begin(), mC2.end());

	std::cout << "\n" << mC;
	std::cout << "\n" << mC2;
	

	return 0;
}