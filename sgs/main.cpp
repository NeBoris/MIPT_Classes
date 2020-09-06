#include <iostream>
#include <iomanip>

#define c 29979245800

int main(){
	char flag = 0;
	int power = 0;
	double value;
	std::string s, temp, numerator = "", denominator = "";

	std::cout << "Enter the value with its full dimension (for reference, enter q): ";

	if(std::cin.peek() == 'q'){
		std::cout << "Entry rules:\n"
				<< "1. There should be one space between the value and the dimension\n"
				<< "2. In dimension, the numerator is separated from the denominator by a fraction ( / ), and the elements in both are separated by a multiplication sign(*)\n"
				<< "3. An entry form with a power of ten is written as \"3.14*10^14\"\n"
				<<"Enter data: ";
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
	//s = "Õ/ Î";

	for(int i = 0; i <= int(s.size()); i++){
		if(s[i] != '/' && s[i] != '*' && i != int(s.size())){
			temp.push_back(s[i]);
		}else{


			if(temp == "Kl" || temp == "A"){
				value /= 10;
				value *= 3;
				power += 10;
				if(temp == "A"){
					denominator += "s";
				}
				temp = "ed.SGSE";
			}else if(temp == "Vb" || temp == "V"){
				power += 2;
				value /= 3;
				if(temp == "Vb"){
					temp == "Mks";
				}else{
					temp.clear();
				}
			}else if(temp == "m"){
				power += 2;
				temp = "sm";
			}else if(temp == "mm"){
				if(power >= 1){
					power -= 1;
				}else{
					value /= 10;
				}
				temp = "sm";
			}else if(temp == "min"){
				value *= 6;
				power += 1;
				temp = "s";
			}else if(temp == "h"){
				value *= 3.6;
				power += 3;
				temp = "s";
			}else if(temp == "kg"){
				power += 3;
				temp = "g";
			}else if(temp == "N"){
				power += 5;
				temp = "din";
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

	std::cout << std::setprecision(2) << value << "*" << 10 << "^" << power << " ";

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



