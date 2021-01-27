#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

class Sort
{
public:
	virtual void sort(std::vector<int> &v) = 0;
	virtual ~Sort() {}
};

class Insertion : public Sort
{
public:
	void sort(std::vector<int>& v) override
	{
		for (auto j = 0U; j < v.size(); ++j)
		{
			for (auto i = j; i < v.size() - 1; ++i)
			{
				if (v[i] > v[i + 1])
					std::swap(v[i], v[i + 1]);
			}
		}
	}
};

class Standart_sort : public Sort
{
public:
	void sort(std::vector<int>& v) override
	{
		std::sort(v.begin(), v.end());
	}
	
};


class Sorter
{
public:
	Sorter(const std::vector<int> &v) :
		m_v(v) {}
	void set_sort(std::shared_ptr<Sort> S)
	{
		S->sort(m_v);
	}

	void print()
	{
		for (auto c : m_v)
		{
			std::cout << c << " ";
		}
	}

private:
	std::vector<int> m_v;
};











class Static_Insertion
{
public:
	void sort(std::vector<int> &v)
	{
		for (auto j = 0U; j < v.size(); ++j)
		{
			for (auto i = 0U; i < v.size() - 1; ++i)
			{
				if (v[i] > v[i + 1])
					std::swap(v[i], v[i + 1]);
			}
		}
	}

};





class Static_standart_sort
{
public:
	void sort(std::vector<int> &v)
	{
		std::sort(v.begin(), v.end());
	}

};


template <typename T>
class Static_sorter : public T
{
public:
	Static_sorter(const std::vector<int> & v) :
		m_v(v) {}

	void make_sort()
	{
		this->sort(m_v);
	}

	void print()
	{
		for (auto c : m_v)
		{
			std::cout << c << " ";
		}
	}

private:
	std::vector<int> m_v;
};











int main()
{
	std::vector<int> v{ 1,3,5,2,4 };

	/*Sorter s(v);

	s.set_sort(std::make_shared<Insertion>());

	s.print();*/

	Static_sorter<Static_Insertion> ST(v);

	ST.make_sort();
	ST.print();


	return 0;
}