#include <iostream>

class Fig_v
{
public:
	virtual void print() = 0;
	~Fig_v() = default;
};

class Circle_v : public Fig_v
{
public:
	Circle_v(int r) :
		radius(r) {}

	virtual void print()
	{
		std::cout << radius << std::endl;
	}

	~Circle_v() = default;

private:
	int radius;
};


template <typename T>
class Figure 
{
public:
	void print()
	{
		self()->m_print();
	}

	virtual ~Figure() = default;
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
		std::cout << m_value << std::endl;
	}

public:
	Circle(int new_value) :
		m_value(new_value) {}

	virtual ~Circle() = default;
private:
	int m_value;
};



int main()
{
	Circle c(13);

	c.print();

	Fig_v* v = new Circle_v(13);

	v->print();

	delete v;
	return 0;
}
