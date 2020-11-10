#include <iostream>

template <typename T>
class Figure 
{
public:
	void print()
	{
		self()->print();
	}
private:
	T* self()
	{
		return static_cast<T*>(this);
	}
};

class Circle : public Figure<Circle>
{
public:
	Circle(int new_value) :
		m_value(new_value) {}
	void print()
	{
		std::cout << m_value;
	}
private:
	int m_value;
};



int main()
{
	Circle c(13);

	return;
}