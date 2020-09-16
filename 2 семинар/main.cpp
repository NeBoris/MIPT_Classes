#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
//#include <sstream>
#include <stdexcept>

void Print(const std::vector<std::vector<double>> &matrix){
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

void Divide(std::vector<double> & vec, double n){
	for(auto &c : vec){
		c /= n;
	}
}

void Clear_column(std::vector<std::vector<double>> &matrix, const int &row, const int &column){
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

	if(row == column && row == int(matrix.size())){
		throw std::invalid_argument("Система несовместна");
	}

	for(int j = 0; j < row; ++j){
		for(int i = column; i < int(matrix[0].size()); ++i){
			temp.push_back(-matrix[j][i]);
		}
		fundam.push_back(temp);
		temp.clear();
	}

	//check for incorrect system
	for(int i = row; i < int(matrix.size()); ++i){
		if(matrix[i][int(matrix[0].size()) - 1] != 0){
			throw std::invalid_argument("Система несовместна");
		}
	}

	for(int j = 0; j < int(matrix.size()) - row; ++j){
		for(int i = 0; i < int(matrix[0].size()) - column; ++i){
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
	int N = 3, flag = 1;
	std::stringstream s("");


	s << "1" << ' ' << "2" << ' ' << "3" << ' ' << "-1" << '\n'
			<< "2" << ' ' << "3" << ' ' << "4" << ' ' << "1" << '\n'
			<< "1" << ' ' << "1" << ' ' << "1" << ' ' << "2" << '\n';
	//		<< "1" << ' ' << "0" << ' ' << "0" << ' ' << "1" << '\n';



	std::cout << "Введите число уравнений в системе: ";
	//std::cin >> N;


	std::cout << "Введите коэффициенты системы уравнений в виде матрицы (нажмите q для справки): " << std::endl;


	std::cin.ignore(1);
	//if(std::cin.peek() == 'q'){
	if(s.peek() == 'q'){
		std::cout << "Правила ввода:\n"
				<< "1. Коэффициенты одного уравнения вводятся в одной строке через пробел\n"
				<< "2. Нулевые коэффициенты обязательны для ввода\n"
				<< "3. При переходе к коэффициентам следующего уравнения нажать 'enter' " << std::endl;
		std::cout << "Введите коэффициенты: " << std::endl;
		//std::cin.ignore(1);
		s.ignore(1);
	}


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
			if(matrix[row][column] == 0)
			{
				if(row != int(matrix.size()) - flag){
					std::swap(matrix[row], matrix[row+flag]);
					--row;
					--column;
					++flag;
					//Print(matrix);
				}else{
					break;
				}
			}else
			{
				Divide(matrix[row], matrix[row][column]);
				//Print(matrix);
				Clear_column(matrix, row, column);
				//Print(matrix);
			}


	}

	try{
		Print(solution(matrix));
		std::cout << "Фундаментальная матрица для данной системы уравнений. Её столбцы являются базисными векторами пространства решений." << std::endl;
	}catch(const std::invalid_argument &ia){
		std::cout << "Invalid argument: " << ia.what() << std::endl;;
	}
	return EXIT_SUCCESS;
}
