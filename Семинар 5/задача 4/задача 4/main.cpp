#include <iostream>
#include "Header.hpp"

int func(int a, int b) {
	return a + b;
}

int main() {
	func(4,5);

	return 0;
}

//необходимо либо дать функциям в файлах разные название, либо убрать одно из определений.
//Желательно убрать функцию в этом файле, где есть функция main()