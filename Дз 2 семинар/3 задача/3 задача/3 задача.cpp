#include <iostream>
#include <vector>

std::size_t search(const std::vector<int>& v, int key) {
	std::size_t left = 0;
	std::size_t right = v.size() - 1;
	std::size_t mid = 0;
	
	while (right - left > 1) {
		mid = left + (right - left) / 2;

		if (key >= v[mid]) {
			left = mid;
		}
		else{
			right = mid;
		}
	}
	
	if (v[right] == key) {
		std::cout << "The index of this element is " << mid;
	}
	else {
		std::cout << "There is no that element!";
	}
	
}

int main()
{
	
	int N, key;

	std::cout << "Enter the number of elements: ";
	std::cin >> N;

	std::vector<int> v(N);

	std::cout << "\nEnter elements: \n";
	for (auto &c : v) {
		std::cin >> c;
	}
	
	std::cout << "What element do you want to find in array? ";
	std::cin >> key;

	search(v, key);
	
	


	return 0;
}
