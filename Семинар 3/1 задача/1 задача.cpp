#include <iostream>
#include <vector>

void merge_sort(std::vector<double>& mas);
void merge_sort(std::vector<double>& mas, std::size_t mas_begin, std::size_t mas_end);
void merge(std::vector<double>& mas, std::size_t mas_begin, std::size_t mas_end);

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

	for (auto c : arr) {
		std::cout << c << " ";
	}

	return 0;
}

void merge_sort(std::vector<double>& mas) {
	if (mas.size() == 1) {
		return;
	}

	std::size_t middle = mas.size() / 2;

	merge_sort(mas, 0, middle);
	merge_sort(mas, middle, mas.size());

	merge(mas, 0, mas.size());
}


void merge_sort(std::vector<double>& mas, std::size_t mas_begin, std::size_t mas_end) {
	if (mas_end - mas_begin == 1 || mas_end == mas_begin) {
		return;
	}

	std::size_t middle = mas_begin + (mas_end - mas_begin) / 2;

	//for (auto i = mas_begin; i < middle; ++i) {
	//	std::cout << mas[i] << " ";
	//}
	//std::cout << '\n';
	//for (auto i = middle; i < mas_end; ++i) {
	//	std::cout << mas[i] << " ";
	//}
	//std::cout << '\n';
	//std::cout << '\n';

	merge_sort(mas, mas_begin, middle);
	merge_sort(mas, middle, mas_end);

	merge(mas, mas_begin, mas_end);
}

void merge(std::vector<double>& mas, std::size_t left, std::size_t right) {
	std::vector<double> result(right - left);

	std::size_t middle = left + (right - left) / 2;
	std::size_t i = left, j = middle, k = 0U;

	for (; i < middle && j < right; ++k) {
		if (mas[i] < mas[j]) {
			result[k] = mas[i];
			++i;
		}
		else if(mas[i] > mas[j]){
			result[k] = mas[j];
			++j;
		}
		else {
			result[k + 1] = result[k] = mas[i];
			++i;
			++j;
		}
	}
	
	for (; i < middle && k < result.size(); ++i, ++k)
		result[k] = mas[i];
	

	for (; j < right && k < result.size(); ++j, ++k)
		result[k] = mas[j];


	for (auto c = left; c < right; ++c) 
		mas[c] = result[c - left];

	

	//std::cout << "\n*******************************************\n";
	//for (auto c : result) {
	//    std::cout << c << " ";
	//}
	//std::cout << "\n*******************************************\n";

}
