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

    for (auto i = 1U; i < arr.size(); ++i) {
        for (auto j = i; j > 0U && arr[j - 1U] > arr[j]; --j) {
                std::swap(arr[j - 1U], arr[j]);
        }
    }

    for (auto& c : arr) {
        std::cout << c << " ";
    }

    return 0;
}
