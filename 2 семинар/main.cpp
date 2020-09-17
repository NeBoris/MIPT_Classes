#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

int find_in_vector(const std::vector<unsigned int> &v, unsigned int k){
	for(auto c = 0U; c < v.size(); ++c){
		if(v[c] == k){
			return c;
		}
	}
	return -1;
}

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

	std::vector< std::vector<double>> fundamental_matrix(*size_e - 1);
	std::vector<double> partial_sol(*size_e - 1, 0.0);

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
	}else{
		for(auto i = 0U, k = 0U; k < *size_c && (i < *size_e - 1); ++i, ++k){
			if(find_in_vector(zero_columns,i) == -1){
				partial_sol[i] = matrix[k].back();
				for(auto c : zero_columns){
					fundamental_matrix[i].push_back(matrix[k][c] == 0 ? matrix[k][c] : -matrix[k][c]);
				}
			}else{
				partial_sol[i] = 0.0;
				for(auto z = 0U; z < zero_columns.size(); ++z){
					find_in_vector(zero_columns,i)  == int(z) ? fundamental_matrix[i].push_back(1.0) : fundamental_matrix[i].push_back(0.0);
				}
				--k;
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
	int* N = new int(4); //amount of equations
	int* M = new int(5); //amount of variables
	std::stringstream s("");
	unsigned int row = 0U;

	std::cout << "Enter amount of equations in a system and number of variables: ";
	//std::cin >> *N >> *M;
	if(*N > *M){
		try_again(N, M);
	}


	//s << 1 << 2 << 3 << 4 << 2 << 5 << 17 << 0 << 3 << -2 << 8 << 1;
	s << "1 0 0 3 1 0 1 0 4 2 0 0 1 5 3 0 0 0 0 4";




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


	std::vector<unsigned int> zero_columns;
	auto k = 0U;
	for(auto i = 0U; k < *size_e - 1 && i < *size_c; ++i, ++k, ++row){
		if(is_equal(matrix[i][k], 0.0)){
			auto j = 0U;
			zero_columns.empty() ? j = i + 1U : j = zero_columns[0];
			for(; j < *size_c && is_equal(matrix[j][k], 0.0); ++j);

			if(j == *size_c){
				zero_columns.push_back(k);
				--i;
				--row;
				continue;
			}
			std::swap(matrix[i], matrix[j]);
		}
		double t = matrix[i][k];
		for(auto m = 0U; m < *size_e; ++m){
			matrix[i][m] /= t;
		}


		for(auto j = 0U; j < *size_c; ++j){
			if(j == i){
				continue;
			}
			double t = matrix[j][k];
			for(auto m = 0U; m < *size_e; ++m){
				matrix[j][m] -= t*matrix[i][m];
			}
		}
	}

	if(k < *size_e){
		while(k != *size_e - 1){
			zero_columns.push_back(k);
			++k;
		}
	}

	/*if(!zero_columns.empty()){
		for(const auto c : zero_columns){
			std::cout << c << " ";
		}
	}*/
	std::cout << '\n';

	if(row < *size_c){
		std::cout << "the system is incompatible";
		return 0;
	}


	print(matrix);

	get_solution(matrix, zero_columns, size_c, size_e);


	return 0;
}
