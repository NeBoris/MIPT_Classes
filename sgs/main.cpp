#include <iostream>
#include <iomanip>


int main(){
	char flag = 0;
	int power = 0;
	double value;
	std::string s, temp, numerator, denominator;

	std::cout << "Введите величину с её полной размерностью (для справки введите q): ";

	if(std::cin.peek() == 'q'){
		std::cout << "Правила ввода:\n"
				<< "1. Между величиной и размерностью должен стоять один пробел\n"
				<< "2. В размерности числитель отделяется от знаменателя дробью (/), а элементы в обоих знаком умножения(*)\n"
				<< "3. Форма записи со степенью десяти записывается в виде \"3.14*10^14\"\n"
				<< "Здесь есть пока Кл, А, м, мм, кг, Вб, В, Н, мин, ч\n"
				<<"Введите данные: ";
		std::cin.ignore(1);
	}


	std::cin >> value;
	while(std::cin.peek() != '^' && std::cin.peek() != ' '){
		std::cin.ignore(1);
	}


	if(std::cin.peek() == '^'){
		std::cin.ignore(1);
		std::cin >> power;
	}

	std::cin >> s;

	//value = 16;
	//power = 9;
	//s = "Н/Кл";

	for(int i = 0; i <= int(s.size()); i++){
		if(s[i] != '/' && s[i] != '*' && i != int(s.size())){
			temp.push_back(s[i]);
		}else{


			if(temp == "Кл" || temp == "А"){
				value /= 10;
				value *= 3;
				power += 10;
				if(temp == "А"){
					denominator += "c";
				}
				temp = "ед.СГСЭ";
			}else if(temp == "Вб" || temp == "В"){
				power += 2;
				value /= 3;
				if(temp == "Вб"){
					temp == "Мкс";
				}else{
					temp.clear();
				}
			}else if(temp == "м"){
				power += 2;
				temp = "см";
			}else if(temp == "мм"){
				if(power >= 1){
					power -= 1;
				}else{
					value /= 10;
				}
				temp = "см";
			}else if(temp == "мин"){
				value *= 6;
				power += 1;
				temp = "с";
			}else if(temp == "ч"){
				value *= 3.6;
				power += 3;
				temp = "с";
			}else if(temp == "кг"){
				power += 3;
				temp = "г";
			}else if(temp == "Н"){
				power += 5;
				temp = "дин";
			}

			if(flag == 0){
				if(i != int(s.size()) && s[i] != '/'){
					numerator += temp + "*";
				}else{
					numerator += temp;
				}
			}else{
				if(i != int(s.size())){
					denominator += temp + "*";
				}else{
					denominator += temp;
				}
			}

			if(s[i] == '/'){
				flag = 1;
			}

			temp.clear();
		}
	}
	if(power != 0){
		std::cout << std::setprecision(2) << value << "*" << 10 << "^" << power << " ";
	}else{
		std::cout << std::setprecision(2) << value << " ";
	}

	if(denominator.empty()){
		if(!numerator.empty()){
			std::cout << numerator;
		}
	}else{
		if(!numerator.empty()){
			std::cout << numerator << "/" << denominator << std::endl;
		}else{
			std::cout << 1 << "/" << denominator << std::endl;
		}
	}

	return 0;
}



