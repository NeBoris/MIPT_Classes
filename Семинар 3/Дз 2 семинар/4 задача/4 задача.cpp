#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string s1, s2,result;
    std::vector<std::vector<std::size_t>> max_elements;

    std::cout << "Please, enter two strings and computer will find lcs: " << std::endl;
    std::cin >> s1 >> s2;

    std::vector< std::vector<std::size_t>> v;

    max_elements.push_back({ 0 });

    for (auto i = 0U; i < s1.size(); ++i) {
        for (auto j = 0U; j < s2.size(); ++j) {
            if (i == 0) {
                i++;
            }
            if (j == 0) {
                j++;
            }
            
            if (s1[i] == s2[j]) {
                v[i][j] = v[i - 1][j - 1] + 1;
                if (v[i][j] > max_elements.back()[0]) {
                    max_elements.push_back({ v[i][j], i });
                }
                
            }
            else {
                if (v[i - 1][j] > v[i][j - 1]) {
                    v[i][j] = v[i - 1][j];
                }
                else {
                    v[i][j] = v[i][j - 1];
                }
            }
        }
    }

    for (const auto c : max_elements) {
        result += c[1];
    }


    return 0;
}
