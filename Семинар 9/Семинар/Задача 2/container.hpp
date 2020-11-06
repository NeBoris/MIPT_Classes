#include <iostream>
#include <vector>
#include <stdexcept>
#include <exception>

namespace not_std {

	template <typename _Ty>
	class my_container {
	public:
		using value_type = _Ty;

		value_type operator[](std::size_t N) const
		{
			if (N >= m_size)
				throw std::out_of_range("Out of vector's range");
			return m_array[N];
		}

		value_type& operator[](std::size_t N)
		{
			if (N >= m_size)
				throw std::out_of_range("Out of vector's range");
			return m_array[N];
		}


		my_container() :
			m_capacity(4), m_array(new value_type[m_capacity]), m_size(0) {}
		my_container(const std::vector < value_type >& v) :
			m_size(v.size()), m_capacity(static_cast<std::size_t>(1.2 * (m_size + 1)))
		{
			m_array = new value_type[m_capacity];
			for (auto i = 0U; i < m_size; ++i)
				m_array[i] = v[i];
		}
		my_container(std::vector < value_type >&& v) :
			m_size(v.size()), m_capacity(static_cast<std::size_t>(1.2 * (m_size + 1)))
		{
			m_array = new value_type[m_capacity];
			for (auto i = 0U; i < m_size; ++i)
				m_array[i] = v[i];

			v.clear();
		}
		my_container(const value_type& vT) :
			m_size(1), m_capacity(static_cast<std::size_t>(1.2 * (m_size + 1)))
		{
			m_array = new value_type[m_capacity];
			*m_array = vT;
		}
		my_container(value_type* vT, std::size_t new_size) :
			m_size(new_size), m_capacity(static_cast<std::size_t>(1.2 * (m_size + 1)))
		{
			if (vT) {
				m_array = new value_type[m_capacity];
				for (auto i = 0U; i < m_size; ++i) {
					m_array[i] = vT[i];
				}
			}
			else {
				m_size = 0;
				m_capacity = 4;
				m_array = new value_type[m_capacity];
			}
		}
		my_container(const my_container& mC) :
			m_size(mC.m_size), m_capacity(static_cast<std::size_t>(1.2 * (m_size + 1)))
		{
			m_array = new value_type(m_capacity);
			for (auto i = 0U; i < m_size; ++i) {
				m_array[i] = mC[i];
			}
		}
		my_container(my_container&& mC) :
			m_array(mC.m_array), m_size(mC.m_size), m_capacity(mC.m_capacity)
		{
			mC.m_size = 0;
			mC.m_capacity = 0;
			mC.m_array = nullptr;
		}

		~my_container()
		{
			if (m_array)
				delete[] m_array;
		}

		bool empty() const noexcept
		{
			return m_size == 0 ? true : false;
		}

		void resize(std::size_t new_size)
		{
			if (new_size > m_size && new_size < m_capacity)
			{
				m_size = new_size;
			}
			else
			{
				m_capacity = static_cast<std::size_t>(1.2 * (m_size + 1));

				value_type* temp = new value_type[m_capacity];


				if (m_array) {
					for (auto i = 0U; i < m_size; ++i)
						temp[i] = m_array[i];

					delete[] m_array;
				}

				m_array = temp;
				m_size = new_size;
				temp = nullptr;
			}

		}

		std::size_t size() const noexcept
		{
			return m_size;
		}

		friend void swap(my_container& lhs, my_container& rhs) noexcept
		{
			std::swap(lhs.m_size, rhs.m_size);
			std::swap(lhs.m_capacity, rhs.m_capacity);
			std::swap(lhs.m_array, rhs.m_array);
		}

		void insert(std::size_t pos, const value_type& vT)
		{
			if (pos > m_size)
			{
				throw std::out_of_range("Inserting to the place out of the container.");
			}
			this->resize(m_size + 1);

			for (auto i = m_size; i > pos; --i)
				m_array[i] = m_array[i - 1];

			m_array[pos] = vT;
		}

		void push_back(const value_type& vT)
		{
			insert(m_size, vT);
		}
		void push_forward(const value_type& vT)
		{
			insert(0, vT);
		}

		value_type* begin() const noexcept
		{
			return m_array;
		}

		value_type* end() const
		{
			if (m_array == nullptr)
				throw std::bad_typeid();

			return m_array + m_size;

		}

		const value_type back() const
		{
			if (m_size == 0)
				throw std::logic_error("Container is empty.");

			return m_array[m_size - 1];
			return *(m_array + m_size);
		}


		friend std::ostream& operator<< (std::ostream& stream, const my_container& cont)
		{
			for (auto i = 0U; i < cont.m_size; ++i)
				stream << cont[i] << " ";

			return stream;
		}

		my_container operator=(const my_container& cont)
		{
			if (this == &cont)
				return *this;

			if (m_array)
				delete[] m_array;

			m_size = cont.m_size;
			m_capacity = 1.2 * (m_size + 1);
			m_array = new value_type[m_capacity];
			for (auto i = 0U; i < m_size; ++i)
				m_array[i] = cont[i];

			return *this;
		}
		my_container operator=(my_container&& cont)
		{
			if (this == &cont)
				return *this;

			if (m_array)
				delete[] m_array;

			swap(this, cont);

			cont.m_size = 0;
			cont.m_array = nullptr;

			return *this;
		}

		my_container operator+= (const my_container<value_type>& cont)
		{
			std::size_t temp = m_size;
			this->resize(m_size + cont.size());

			for (auto i = 0; i < cont.m_size(); ++i)
				m_array[temp + i] = cont[i];

			return *this;
		}
		my_container operator+ (const my_container<value_type>& cont) const
		{
			my_container<value_type> temp(*this);
			temp += cont;

			return temp;
		}

		bool operator>(const my_container& cont) const noexcept
		{
			return this->size() > cont.size();
		}
		bool operator<(const my_container& cont) const noexcept
		{
			return !operator>(*this, cont);
		}
		bool operator==(const my_container& cont) const
		{
			if (this->size() != cont.size())
				return false;

			for (auto i = 0U; i < m_size; ++i)
				if (m_array[i] != cont[i])
					return false;

			return true;
		}
		bool operator!=(const my_container& cont) const
		{
			return !operator==(*this, cont);
		}
		bool operator>=(const my_container& cont) const
		{
			return (operator==(*this, cont)) || (operator>(*this, cont));
		}
		bool operator<=(const my_container& cont) const
		{
			return (operator==(*this, cont)) || (operator<(*this, cont));
		}



	private:
		value_type* m_array;
		std::size_t m_size;
		std::size_t m_capacity;
	};

}