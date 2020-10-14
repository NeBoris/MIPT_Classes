#include <iostream>

class exxxample {
public:
	class Keey {
	private:
		Keey() {};
		friend int get_sum(exxxample& k);
	};
	int get_v1(const Keey&) const{
		return v1;
	}
	int get_v2(const Keey&) const {
		return v2;
	}
private:
	int v1 = 13;
	int v2 = 14;
	int v3 = 16;

};


int get_sum(exxxample& k) {
	exxxample::Keey b;

	return k.get_v1(b) + k.get_v2(b);
}


int main() {
	exxxample b;

	std::cout << get_sum(b);


	return 0;
}
