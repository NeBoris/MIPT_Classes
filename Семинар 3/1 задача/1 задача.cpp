#include <iostream>
#include <vector>
#include <algorithm>

void merge_sort(std::vector<double>& v);
std::vector<double> merge(const std::vector<double>& v1, const std::vector<double>& v2);




int main() {
	int N;

	std::cout << "Enter the number of elements in array: ";
	std::cin >> N;

	std::vector<double> arr(N, 0.0);
	
	std::cout << "Please enter an array to get it back sorted: ";
	for (auto& c : arr) {
		std::cin >> c;
	}

	merge_sort(arr);

	for (auto &c : arr) {
		std::cout << c << " ";
	}

	return 0;
}


void merge_sort(std::vector<double>& v) {
	if (v.size() == 1) {
		return;
	}

	std::size_t middle = v.size() / 2;
	std::vector<double> temp(middle);
	std::size_t N = 0U;

	std::for_each(v.begin(), v.begin() + middle, [&temp, &N](auto c) {
		temp[N] = c;
		++N;
		});
	v.erase(v.begin(), v.begin() + middle);

	//for (auto& c : v) {
	//	std::cout << c << " ";
	//}
	//std::cout << '\n';
	//for (auto& c : temp) {
	//	std::cout << c << " ";
	//}
	//std::cout << '\n';
	//std::cout << '\n';


	merge_sort(v);
	merge_sort(temp);

	v = merge(v, temp);
}




std::vector<double> merge(const std::vector<double>& v1, const std::vector<double>& v2) {
	std::vector<double> result(v1.size() + v2.size());

	auto i = 0U, j = 0U, k = 0U;

	while (i < v1.size() && j < v2.size() && k < result.size()) {
		if (v1[i] > v2[j]) {
			result[k] = v2[j];
			++j;
		}
		else if (v1[i] < v2[j])
		{
			result[k] = v1[i];
			++i;
		}
		else {
			result[k + 1] = result[k] = v1[i];
			++k;
			++i;
			++j;
		}

		++k;
	}

	if (i != v1.size()) {
		for (; i < v1.size() && k < result.size(); ++i, ++k)
			result[k] = v1[i];
	}

	if (j != v2.size()) {
		for (; j < v2.size() && k < result.size(); ++j, ++k)
			result[k] = v2[j];
	}

	//std::cout << "\n*******************************************\n";
	//for (auto& c : result) {
	   // std::cout << c << " ";
	//}
	//std::cout << "\n*******************************************\n";

	return result;
}
