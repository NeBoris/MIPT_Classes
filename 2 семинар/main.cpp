#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
//#include <sstream>
#include <stdexcept>


//rint - print matrix
void print(const std::vector<std::vector<double>> &matrix){
	for(const auto &g : matrix){
		for(const auto &c : g){
			std::cout << std::setw(5) << std::right;
			if(c == -0){
				std::cout << 0 << " ";
			}else{
				std::cout << c << " ";
			}
		}
		std::cout << '\n';
	}
}


//print_solution - print partial solution and fundamental matrix
void print_solution(const std::vector<std::vector<double>> &matrix){
	std::cout << "Partial solution: \n";
	for(const auto &g : matrix){
		std::cout << std::setw(5) << std::right;
		if(g[int(g.size()) - 1] == -0){
			std::cout << 0;
		}else{
			std::cout << g[int(g.size()) - 1];
		}
		std::cout << '\n';
	}

	std::cout << "\nFundamental matrix:\n";

	for(const auto &g : matrix){
		for(auto i = 0; i < int(g.size()) - 1; ++i){
			std::cout << std::setw(5) << std::right;
			if(g[i] == -0){
				std::cout << 0 << " ";
			}else{
				std::cout << g[i] << " ";
			}
		}
		std::cout << '\n';
	}
}

//divide - divide row (vector) by number n
void divide(std::vector<double> & vec, double n){
	for(auto &c : vec){
		c /= n;
	}
}

//clear_column - subtracts the given row from each
//				 row multiplied by the corresponding coefficient
void clear_column(std::vector<std::vector<double>> &matrix, const int &row, const int &column){
	int temp;

	for(int i = 0; i < int(matrix.size()); ++i){
		temp = matrix[i][column];
		if(i == row){
			continue;
		}
		for(int j = 0; j < int(matrix[i].size()); ++j){
			matrix[i][j] -= matrix[row][j] * temp;
		}
	}
}

//solution - returns matrix with the last column - partial solution
//			 the rest columns are columns of fundamental matrix
std::vector<std::vector<double>> solution(const std::vector<std::vector<double>> &matrix){
	std::vector<std::vector<double>> fundam;
	std::vector<double> temp;
	int row, column;

	for(row = 0, column = 0; row < int(matrix.size()) &&
	column < int(matrix[0].size()); ++row, ++column){
		if(matrix[row][column] != 1.0){
			break;
		}
	}
	if(row == int(matrix.size())){
		--row;
	}

	//print(matrix);
	//std::cout << "\n" << row << " " << column << std::endl;
	//check for incorrect system
	for(int i = row; i < int(matrix.size()); ++i){
		if(matrix[i][int(matrix[0].size()) - 1] != 0){
			throw std::invalid_argument("The system is incompatible");
		}
	}

	if(column == int(matrix[0].size())){
		--column;
	}

	for(int j = 0; j < row; ++j){
		for(int i = column; i < int(matrix[0].size()); ++i){
			if(i == int(matrix[0].size()) - 1){
				temp.push_back(matrix[j][i]);
			}else{
				temp.push_back(-matrix[j][i]);
			}
		}
		fundam.push_back(temp);
		temp.clear();
	}

	for(int j = 0; j < int(matrix.size()) - row; ++j){
		for(int i = 0; i < int(matrix[0].size()) - column; ++i){
			if(i == int(matrix[0].size()) - column - 1){
				temp.push_back(0);
				continue;
			}
			if(i == j){
				temp.push_back(1);
			}else{
				temp.push_back(0);
			}
		}
		fundam.push_back(temp);
		temp.clear();
	}


	return fundam;
}

int main(){
	std::vector<std::vector<double>> matrix;
	std::vector<double> temp;
	double c;
	int N = 3, flag = 1;					//flag is used to change rows if dioganal element is 0
	std::stringstream s("");


	 /*     s << "1" << ' ' << "2" << ' ' << "3" << ' ' << "-1" << '\n'
			<< "2" << ' ' << "3" << ' ' << "4" << ' ' << "1" << '\n'
			<< "1" << ' ' << "1" << ' ' << "1" << ' ' << "2" << '\n';
	//		<< "1" << ' ' << "0" << ' ' << "0" << ' ' << "1" << '\n';*/
	      s << "6" << ' ' << "-1" << ' ' << "1" << ' ' << "-1" << '\n'
			<< "5" << ' ' << "-5" << ' ' << "5" << ' ' << "0" << '\n'
			<< "4" << ' ' << "-9" << ' ' << "9" << ' ' << "1" << '\n';
	//		<< "1" << ' ' << "0" << ' ' << "0" << ' ' << "1" << '\n';

	/*	  s << "1" << ' ' << "0" << ' ' << "0" << ' ' << "0" << '\n'
			<< "0" << ' ' << "1" << ' ' << "0" << ' ' << "0" << '\n'
			<< "0" << ' ' << "0" << ' ' << "1" << ' ' << "0" << '\n'
			<< "0" << ' ' << "0" << ' ' << "0" << ' ' << "1" << '\n';*/



	std::cout << "Enter the number of equations in the system: ";
	//std::cin >> N;


	std::cout << "Enter coefficients (press q for help): " << std::endl;


	//std::cin.ignore(1);
	//if(std::cin.peek() == 'q'){
	if(s.peek() == 'q'){
		std::cout << "Rules:\n"
				<< "1. Enter the coefficients of a single equation in a single line separated by a space\n"
				<< "2. Zero coefficients are required for entering\n"
				<< "3. When going to the coefficients of the next equation, click 'enter' " << std::endl;
		std::cout << "Enter the coefficients: " << std::endl;
		//std::cin.ignore(1);
		s.ignore(1);
	}

	//fill the matrix whith coefficients
	for(int i = 0; i < N; i++){
		//if(std::cin.peek() == 10){
		if(s.peek() == 10){
			//std::cin.ignore(1);
			s.ignore(1);
		}
		//while(std::cin.peek() != 10){
		while(s.peek() != 10){
			//std::cin >> c;
			s >> c;
			temp.push_back(c);
		}
		matrix.push_back(temp);
		temp.clear();
	}

	for(auto column = 0, row = 0; column < int(matrix[row].size()) &&
	row < int(matrix.size()); ++column,++row){

			//std::cout << row << "-" << column << " '" << matrix[row][column] << "'" << std::endl;
			if(matrix[row][column] == 0)	//swap the rows if dioganal element in current one is 0
			{
				if(row != int(matrix.size()) - flag){
					std::swap(matrix[row], matrix[row+flag]);
					--row;
					--column;
					++flag;
					//print(matrix);
				}else{
					break;
				}
			}else
			{
				//make this diagonal element 1 (and divide other elements in row)
				divide(matrix[row], matrix[row][column]);
				//Print(matrix);
				//make other elements in column 0
				clear_column(matrix, row, column);
				print(matrix);
			}


	}

	//Print(matrix);

	try{
		print_solution(solution(matrix));
	}catch(const std::invalid_argument &ia){
		std::cout << "Error! " << ia.what() << std::endl;;
	}
	return EXIT_SUCCESS;
}
