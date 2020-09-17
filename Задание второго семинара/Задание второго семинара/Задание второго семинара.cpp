#include <iostream>
#include <vector>



int main()
{
    int N;

    std::cout << "Please, enter the number of elements: ";
    std::cin >> N;

    std::vector<double> arr(N);

    std::cout << "\nEnter the elements: \n";
    for (auto& c : arr) {
        std::cin >> c;
    }

    for (auto i = 0U; i < arr.size(); ++i) {
        for (auto j = 1U; j < arr.size(); ++j) {
            if (arr[j - 1] > arr[j]) {
                std::swap(arr[j - 1], arr[j]);
            }
        }
    }

    for (auto& c : arr) {
        std::cout << c << " ";
    }

    return 0;
}
