#include <iostream>
#include <string>
#include <sstream>

struct time {
	time(const int new_hours, const int new_minutes, const int new_seconds, const int new_milliseconds) :
		hours(new_hours % 24 + new_minutes / 60 + new_seconds / 60 + new_milliseconds / 1000),
		minutes(new_minutes % 60 + new_seconds / 60 + new_milliseconds / 1000),
		seconds(new_seconds % 60 + new_milliseconds / 1000),
		milliseconds(new_milliseconds % 1000) {}

	std::string for_print() const {
		std::stringstream result;
		result << hours << ":" << minutes << ":" << seconds << ":" << milliseconds;
		return result.str();
	}
	
	~time(){}

	unsigned int hours : 5;
	unsigned int minutes : 6;
	unsigned int seconds : 6;
	unsigned int milliseconds : 10;
};

int main() {
	time new_time(13, 65, 14, 1025);

	std::cout << new_time.for_print();

	return 0;
}
