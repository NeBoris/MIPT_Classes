#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

void print(const std::vector< std::vector<double> > &matrix){
	for(const auto c : matrix){
		for(const auto x : c){
			std::cout << std::setw(5) << std::right;
			std::cout << x << " ";
		}
		std::cout << std::endl;
	}
}

bool is_equal(double lhs, double rhs){
	const double epsilon = 0.0000001;

	return abs(lhs - rhs) < epsilon;
}

int main(){
	double* temp = new double;
	int* N = new int; //amount of equations
	int* M = new int; //amount of variables

	std::cout << "Enter amount of equations in a system and number of variables: ";
	std::cin >> *N >> *M;

	std::vector< std::vector<double> > matrix(*N);

	std::cout << "Enter coefficients: \n";

	for(auto &c : matrix){
		for(int j = 0; j < *M; ++j){
			std::cin >> *temp;
			c.push_back(*temp);
		}
	}

	delete N;
	delete M;

	auto* size_e = new auto(matrix.size());
	auto* size_c = new auto(matrix[0].size());

	auto i = 0U;

	for(; i < *size_e && i < *size_c; ++i){
		if(is_equal(matrix[i][i], 0.0)){
			auto j = i + 1U;
			for(; j < *size_e && is_equal(matrix[j][i], 0.0); ++j);

			if(j == *size_e){
				continue;
			}
			std::swap(matrix[i], matrix[j]);
		}
		for(auto el : matrix[i]){
			el /= matrix[i][i];
		}
		for(auto j = 0U; j < *size_c; ++j){
			if(j == i){
				continue;
			}
			double k = matrix[j][i];
			for(auto m = 0U; m < *size_c; ++m){
				matrix[j][m] -= k*matrix[i][m];
			}
		}
	}

	print(matrix);

	if(i == *size_c){
		matrix.erase(matrix.begin() + i, matrix.end());
		*size_c = i;
	}


	print(matrix);


	return 0;
}
