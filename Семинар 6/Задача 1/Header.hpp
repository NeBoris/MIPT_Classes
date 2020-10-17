#pragma once
#include <iostream>
#include <vector>

namespace use {
	class Example {
	public:
		Example();
		Example(int a);
		Example(int* array, int its_size);
		Example(std::vector<int> vec);
		Example(const Example&);
		Example(Example&&);

		~Example() = default;

		friend std::ostream& operator<<(std::ostream& stream, const Example& a);

		Example& operator=(const Example& other);
		Example& operator=(Example&& other);

		Example& operator+=(const Example&);

		friend bool operator==(const Example&, const Example&);


	private:
		int* m_arr;
		std::size_t m_size;
		std::vector<int> m_vec;
	};
}