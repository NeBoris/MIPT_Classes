#include <iostream>
#include <iomanip>

#define c 29979245800

int main(){
	char flag = 0;
	int power = 0;
	double value;
	std::string s, temp, numerator = "", denominator = "";

	std::cout << "������� �������� � � ������ ������������ (��� ������� ������� q): ";

	if(std::cin.peek() == 'q'){
		std::cout << "������� �����:\n"
				<< "1. ����� ��������� � ������������ ������ ������ ���� ������\n"
				<< "2. � ����������� ��������� ���������� �� ����������� ������ (/), � �������� � ����� ������ ���������(*)\n"
				<< "3. ����� ������ �� �������� ������ ������������ � ���� \"3.14*10^14\"\n"
				<<"������� ������: ";
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
	//s = "�/��";

	for(int i = 0; i <= int(s.size()); i++){
		if(s[i] != '/' && s[i] != '*' && i != int(s.size())){
			temp.push_back(s[i]);
		}else{


			if(temp == "��" || temp == "�"){
				value /= 10;
				value *= 3;
				power += 10;
				if(temp == "�"){
					denominator += "c";
				}
				temp = "��.����";
			}else if(temp == "��" || temp == "�"){
				power += 2;
				value /= 3;
				if(temp == "��"){
					temp == "���";
				}else{
					temp.clear();
				}
			}else if(temp == "�"){
				power += 2;
				temp = "��";
			}else if(temp == "��"){
				if(power >= 1){
					power -= 1;
				}else{
					value /= 10;
				}
				temp = "��";
			}else if(temp == "���"){
				value *= 6;
				power += 1;
				temp = "�";
			}else if(temp == "�"){
				value *= 3.6;
				power += 3;
				temp = "�";
			}else if(temp == "��"){
				power += 3;
				temp = "�";
			}else if(temp == "�"){
				power += 5;
				temp = "���";
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



