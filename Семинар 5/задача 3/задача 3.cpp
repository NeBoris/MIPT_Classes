#include <iostream>


class example {
public:
	class Key {
	private:
		friend void get_value1(int c, const example& value);
	public:
		Key();
	};

	int Access(example::Key) const {
		return value1;
	}

private:
	int value1 = 13;
	int value2 = 14;
	int value3 = 15;
};

void get_value1(int c, const example& value) {
	example::Key b;
	std::cout << c * value.Access( b ) << std::endl;
}

int main() {
	example b;


	get_value1(2, b);

	return 0;
}