#include <iostream>

using namespace std;

template<typename T>
class Vector
{
private:
	int capacity;
	int m_size;
	T* container;
public:
	Vector()
	{
		capacity = 0;
		m_size = 0;
		container = nullptr;
	}

	const int& size()
	{
		return m_size;
	}

	const T& operator [] (const int &index)
	{
		return container[index];
	}

	~Vector()
	{
		delete[] container;
	}

};

int main()
{
	Vector<int>vector;

	return 0;
}

