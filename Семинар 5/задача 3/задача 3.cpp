#include <iostream>

void get_value1(example value);

class example {
public:
	class Key {
		friend void get_value1(int value);
		Key();
	};

	void Access(const Key&) {
		get_value1 (value1);
	}

private:
	int value1 = 13;
	int value2 = 14;
	int value3 = 15;
};

void get_value1(example value) {
	std::cout << value << std::endl;
}

int main() {
	example b;




	return 0;
}