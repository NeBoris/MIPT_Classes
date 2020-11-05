#include <iostream>
#include <vector>
#include <stdexcept>
#include <exception>

template <typename _Ty>
class my_container {
public:
	using value_type = _Ty;

	my_container() :
		m_array(nullptr), m_size(0) {}
	my_container(const std::vector < value_type >& v) :
		m_size(v.size()) 
	{
		for (auto i = 0U; i < m_size; ++i)
			*(m_array + i) = v[i];
	}
	my_container(std::vector < value_type >&& v) :
		m_size(v.size())
	{
		for (auto i = 0U; i < m_size; ++i)
			*(m_array + i) = v[i];

		v.empty();
	}
	my_container(const value_type& vT) :
		m_size(1)
	{
		*m_array = vT;
	}
	my_container(value_type* vT, std::size_t new_size) :
		m_size(new_size)
	{
		if (vT) {
			for (auto i = 0U; i < m_size; ++i) {
				*(m_array + i) = *(m_vT + i);
			}
		}
		else {
			m_size = 0;
			m_array = nullptr;
		}
	}
	my_container(const my_container& mC) :
		m_size(mC.m_size)
	{
		for (auto i = 0U; i < m_size; ++i) {
			*(m_array + i) = *(m_mC + i);
		}
	}
	my_container(my_container&& mC) :
		m_array(mC.m_array), m_size(mC.m_size)
	{
		mC.m_size = 0;
		mC.m_array = nullptr;
	}

	~my_container() 
	{
		if (m_array)
			delete[] m_array;
	}

	void push_back(const value_type& vT) 
	{
		*(m_array + m_size) = vT;
		m_size++;
	}
	void push_forward(const value_type& vT) 
	{
		for (auto i = m_size; i > 0; --i)
			*(m_array + i) = *(m_array + i - 1);

		*m_array = vT;
		m_size++;
	}
	void insert(std::size_t pos, const value_type& vT) 
	{
		if (pos > m_size) 
		{
			throw std::out_of_range("Inserting to the place out of the container.")
		}

		for (auto i = m_size; i > 0; --i)
			*(m_array + i) = *(m_array + i - 1);

		*(m_array + pos)  = vT;
		m_size++;
	}

	value_type* begin() 
	{
		return m_array;
	}
	value_type* end() 
	{
		return m_array + m_size - 1;
	}

	value_type back() 
	{
		return *(m_array + m_size - 1);
	}

	friend std::ostream& operator<< (std::ostream& stream, const my_container& cont);
	friend std::istream& operator>> (std::istream& stream, my_container& cont);

	my_container operator=(const my_container& cont);
	my_container operator=(my_container&& cont);
	
	my_container operator+= (const my_container cont);
	my_container operator-= (const my_container cont);
	my_container operator+ (const my_container cont);
	my_container operator- (const my_container cont);

	bool operator>(const my_container& cont);
	bool operator<(const my_container& cont);
	bool operator>=(const my_container& cont);
	bool operator<=(const my_container& cont);
	bool operator==(const my_container& cont);
	bool operator!=(const my_container& cont);

	bool empty()
	{
		return m_size == 0 ? true : false;
	}

	void resize(std::size_t new_size);

	std::size_t size() {
		return m_size;
	}

	void swap(my_container& cont);


private:
	value_type* m_array;
	std::size_t m_size;
};