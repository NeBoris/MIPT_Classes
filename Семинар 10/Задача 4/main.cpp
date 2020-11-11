#include <iostream>

template <typename T>
class Figure 
{
public:
	void print()
	{
		self()->m_print();
	}
private:
	T* self()
	{
		return static_cast<T*>(this);
	}
};

class Circle : public Figure<Circle>
{
	friend class Figure<Circle>;
private:
	void m_print()
	{
		std::cout << m_value;
	}

public:
	Circle(int new_value) :
		m_value(new_value) {}
private:
	int m_value;
};



int main()
{
	Circle c(13);

	c.print();

	return 0;
}