#include <iostream>
#include <string>
#include <vector>

struct Student;

struct Course {
	Course() :
		name("No name") {}

	Course(const std::string new_name) :
		name(new_name) {}

	void print_students() {
		for (auto& c : members) {

		}
	}
	
	~Course(){}
	
	std::string name;
	std::vector<Student*> members;
};

struct Student {
	Student(const std::string new_name, const std::string new_last_name) :
		name(new_name), last_name(new_last_name) {}

	void add_class(const std::string name_of_class, std::vector<Course>& CRS) {
		Course* ptr = new Course;
		for (auto& c : CRS) {
			if (c.name == name_of_class) {
				ptr = &c;
				classes.push_back(ptr);
				ptr->members.push_back(this);
			}
		}
	}

	void print_classes() {
		for (auto c : classes) {
			std::cout << c->name;
		}
	}
	
	~Student(){}

	std::string name;
	std::string last_name;
	std::vector<Course*> classes;
};



int main() {
	std::vector<Student> st;
	std::vector<Course> crs;

	Student s1("Boris", "Nekrasov");
	Course c1("Molecular physics");
	Course c2("Quantum physics");
	Course c3("Atom physics");

	crs.push_back(c1);
	crs.push_back(c2);
	crs.push_back(c3);
	st.push_back(s1);

	st[0].add_class("Quantum physics", crs);
	st[0].add_class("Atom physics", crs);
	st[0].print_classes();

}
