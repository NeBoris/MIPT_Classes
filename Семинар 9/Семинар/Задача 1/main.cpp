#include <iostream>
#include <algorithm>
#include <functional>


template <typename T, typename FUNC, std::size_t N>
void merge_sort(T (&array) [N], T (&buf) [N], FUNC f, int left, int right) {
    if (left < right) {
        int m = left + (right - left) / 2;
        merge_sort(array, buf, f, left, m);
        merge_sort(array, buf, f, m + 1, right);

        int k = left;
        for (int i = left, j = m + 1; i <= m || j <= right; ) {
            if (j > right || (i <= m && f(array[i],array[j]) )) {
                buf[k] = array[i];
                ++i;
            }
            else {
                buf[k] = array[j];
                ++j;
            }
            ++k;
        }
        for (int i = left; i <= right; ++i) {
            array[i] = buf[i];
        }
    }
}


template <typename T, std::size_t N, typename FUNC>
void my_sort(T (&array) [N], FUNC f) {
    if (N != 0) {
        T buf[N];
        merge_sort(array, buf, f, 0, N - 1);
    }
}

template <typename T, std::size_t N>
void my_sort(T(&array)[N]) {
    if (N != 0) {
        T buf[N];
        merge_sort(array, buf, [](const T& lhs, const T& rhs) {return lhs < rhs; }, 0, N - 1);
    }
}



template <typename T, typename FUNC>
void merge_sort_(T* array, T* buf, std::size_t N, FUNC f, int left, int right) {
    if (left < right) {
        int m = left + (right - left) / 2;
        merge_sort_(array, buf, N, f, left, m);
        merge_sort_(array, buf, N, f, m + 1, right);

        int k = left;
        for (int i = left, j = m + 1; i <= m || j <= right; ) {
            if (j > right || (i <= m && f(*(array + i), *(array + j)))) {
                *(buf + k) = *(array + i);
                ++i;
            }
            else {
                *(buf + k) = *(array + j);
                ++j;
            }
            ++k;
        }
        for (int i = left; i <= right; ++i) {
            *(array + i) = *(buf + i);
        }
    }
}

template <typename T, typename FUNC = std::function<bool(const T& lhs, const T& rhs)>>
void my_sort(T* array, std::size_t N, FUNC f = [](const T& lhs, const T& rhs) {return lhs < rhs; }) {
    if (N != 0) {
        T* buf = new T[N];
        merge_sort_(array, buf, N, f, 0, N - 1);
        delete[] buf;
    }
}


int main() {
    int arr[] = { 5,45,3,235,1 };
    double arr2[] = { 6.45, 6.85, 6.98, 6.21, 6.128 };
    int* arr3 = new int[5];

    *(arr3) = 12;
    *(arr3 + 1) = -3254;
    *(arr3 + 2) = 3463;
    *(arr3 + 3) = 1;
    *(arr3 + 4) = 234;

    std::cout << std::endl << "arr3: ";
    for (int i = 0; i < 5; ++i)
    {
        std::cout << *(arr3 + i) << " ";
    }
    std::cout << std::endl << "arr3: ";
    for (int i = 0; i < 5; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl << "arr2: ";
    for (int i = 0; i < 5; ++i)
    {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    my_sort(arr3, 5);
    my_sort(arr);
    my_sort(arr2);

    std::cout << std::endl << "arr3: ";
    for (int i = 0; i < 5; ++i)
    {
        std::cout << *(arr3 + i) << " ";
    }
    std::cout << std::endl << "arr3: ";
    for (int i = 0; i < 5; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl <<"arr2: ";
    for (int i = 0; i < 5; ++i)
    {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;


    my_sort(arr3, 5, [](const int& lhs, const int& rhs) {return lhs > rhs; });
    my_sort(arr, [](const int& lhs, const int& rhs) {return lhs > rhs; });
    my_sort(arr2, [](const double& lhs, const double& rhs) {return lhs > rhs; });

    std::cout << std::endl << "arr3: ";
    for (int i = 0; i < 5; ++i)
    {
        std::cout << *(arr3 + i) << " ";
    }
    std::cout << std::endl << "arr3: ";
    for (int i = 0; i < 5; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl << "arr2: ";
    for (int i = 0; i < 5; ++i)
    {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;


    return 0;
}