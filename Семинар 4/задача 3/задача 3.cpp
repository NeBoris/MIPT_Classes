#include <iostream>
#include <string>
#include <sstream>



struct time {
	time(const int new_year, const int new_month, const int new_day, const int new_hours, const int new_minutes, const int new_seconds, const int new_milliseconds) :
		year(new_year + new_month / 12 + new_day / 31 + new_hours % 24 + new_minutes / 60 + new_seconds / 60 + new_milliseconds / 1000),
		month(new_month % 12 + new_day / 31 + new_hours % 24 + new_minutes / 60 + new_seconds / 60 + new_milliseconds / 1000),
		day(new_day % 31 + new_hours % 24 + new_minutes / 60 + new_seconds / 60 + new_milliseconds / 1000),
		hours(new_hours % 24 + new_minutes / 60 + new_seconds / 60 + new_milliseconds / 1000),
		minutes(new_minutes % 60 + new_seconds / 60 + new_milliseconds / 1000),
		seconds(new_seconds % 60 + new_milliseconds / 1000),
		milliseconds(new_milliseconds % 1000) {}

	std::string for_print() const {
		std::stringstream result;
		result << year << ":" << month << ":" << day << "     " << hours << ":" << minutes << ":" << seconds << ":" << milliseconds;
		return result.str();
	}
	
	~time(){}

	unsigned int year;
	unsigned int month : 4;
	unsigned int day : 5;
	unsigned int hours : 5;
	unsigned int minutes : 6;
	unsigned int seconds : 6;
	unsigned int milliseconds : 10;
};

int main() {
	time new_time(2020, 10, 1, 13, 65, 14, 1025);

	std::cout << new_time.for_print();

	return 0;
}
