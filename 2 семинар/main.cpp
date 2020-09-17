#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

void print(const std::vector< std::vector<double> > &matrix){
	for(const auto c : matrix){
		for(const auto x : c){
			std::cout << std::setprecision(2) << std::setw(5) << std::right;
			std::cout << x << " ";
		}
		std::cout << std::endl;
	}
}

bool is_equal(double lhs, double rhs){
	const double epsilon = 0.0000001;

	return abs(lhs - rhs) < epsilon;
}

void try_again(int* N, int* M){
	std::cout << "\nAmount of equations in a system must be less or equal to number of variables.\nTry again: ";
	std::cin >> *N >> *M;
	if(*N > *M){
		try_again(N, M);
	}
}

void get_solution(const std::vector< std::vector<double>> &matrix, const std::vector<unsigned int> &zero_columns,
		unsigned int* size_c, unsigned int* size_e){

	std::vector< std::vector<double>> fundamental_matrix(*size_e);
	std::vector<double> partial_sol(*size_e, 0.0);

	if(zero_columns.empty()){

		for(auto i = 0U; i < *size_c; ++i){
			partial_sol[i] = matrix[i].back();
		}

		if(*size_c < *size_e - 1){
			for(auto i = 0U; i < *size_e - 1; ++i){
				for(auto j = *size_c; j < *size_e - 1 && i < *size_c; ++j){
					fundamental_matrix[i].push_back(-matrix[i][j]);
				}
				for(auto j = 0U; (j < *size_e - *size_c - 1)&& i >= *size_c; ++j){
					(i - *size_c) == j ?  fundamental_matrix[i].push_back(1.0) : fundamental_matrix[i].push_back(0.0);
				}
			}

		}
	}

	std::cout << "Partial solution:\n";
	for(const auto c : partial_sol){
		std::cout << c << '\n';
	}

	std::cout << "Fundamental matrix:\n";
	print(fundamental_matrix);
}

int main(){
	double* temp = new double;
	int* N = new int;//(3); //amount of equations
	int* M = new int;//(4); //amount of variables
	std::stringstream s("");

	std::cout << "Enter amount of equations in a system and number of variables: ";
	std::cin >> *N >> *M;
	if(*N > *M){
		try_again(N, M);
	}


	//s << 1 << 2 << 3 << 4 << 2 << 5 << 17 << 0 << 3 << -2 << 8 << 1;
	s << "1 0 0 4 5 1 0 1 0 7 8 10 0 0 1 4 3 12";




	std::vector< std::vector<double> > matrix(*N);

	std::cout << "Enter coefficients: \n";

	for(auto &c : matrix){
		for(int j = 0; j < *M; ++j){
			//std::cin >> *temp;
			s >> *temp;
			c.push_back(*temp);
		}
	}


	delete N;
	delete M;

	unsigned int* size_e = new unsigned int(matrix[0].size());
	unsigned int* size_c = new unsigned int(matrix.size());

	auto i = 0U;
	std::vector<unsigned int> zero_columns;

	for(; i < *size_e && i < *size_c; ++i){
		if(is_equal(matrix[i][i], 0.0)){
			auto j = 0U;
			zero_columns.empty() ? j = i + 1U : j = zero_columns[0];
			for(; j < *size_c && is_equal(matrix[j][i], 0.0); ++j);

			if(j == *size_c){
				zero_columns.push_back(i);
				continue;
			}
			std::swap(matrix[i], matrix[j]);
		}
		double k = matrix[i][i];
		for(auto m = 0U; m < *size_e; ++m){
			matrix[i][m] /= k;
		}


		for(auto j = 0U; j < *size_c; ++j){
			if(j == i){
				continue;
			}
			double k = matrix[j][i];
			for(auto m = 0U; m < *size_e; ++m){
				matrix[j][m] -= k*matrix[i][m];
			}
		}
	}

	if(!zero_columns.empty()){
		for(const auto c : zero_columns){
			std::cout << c << " ";
		}
	}
	std::cout << '\n';

	print(matrix);

	get_solution(matrix, zero_columns, size_c, size_e);


	return 0;
}
