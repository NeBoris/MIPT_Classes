#include <iostream>
#include <vector>

std::size_t search(const std::vector<int>& v, int key) {
	std::size_t left = 0;
	std::size_t right = v.size() - 1;
	std::size_t mid = 0;
	
	while (v[mid] != key && left == right) {
		mid = left + (right - left) / 2;

		if (key > v[mid]) {
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}
	
	return left == right ? v[left] : v[mid];
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

	if (key >= v[0] && key <= v.back()) {
		std::cout << "The index of this element is " << search(v, key);
	}
	else {
		std::cout << "There is no that element!";
	}
	


	return 0;
}
