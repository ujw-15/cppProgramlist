#include <iostream>

using namespace std;

template<typename T>
class Graph
{
private:
	int size;		// 정점의 개수
	int count;		// 인접 행렬의 크기
	int capacity;	// 최대 용량

	T* v;			// 정점의 집합
	int** m;		// 인접 행렬

public:
	Graph()
	{
		size = 0;
		count = 0;
		capacity = 0;

		v = nullptr;
		m = nullptr;
	}

	void resize(int newSize)
	{
		capacity = newSize;
		T* container = new T[capacity];

		for (int i = 0; i < capacity; i++)
		{
			container[i] = NULL;
		}
		for (int i = 0; i < size; i++)
		{
			container[i] = v[i];
		}

		delete[] v;

		v = container;
	}

	void push(T data)
	{
		if (capacity <= 0)
		{
			resize(1);
		}
		else if (size >= capacity)
		{
			resize(capacity * 2);
		}

		v[size++] = data;
	}

	void edge(int i, int j)
	{
		if (size <= 0)
		{
			cout << "adjacency matrix is empty" << endl;
		}
		else if (i >= size || j >= size)
		{
			cout << "index out of range" << endl;
		}
		else
		{
			if (m == nullptr)
			{

				count = size;

				m = new int[count];

				for (int i = 0; i < count; i++)
				{
					m[i] = new int[size];
				}
				for (int j = 0; j < count; j++)
				{
					m[i][j] = 0;
				}

			}
		}
	}

};

int main()
{
	Graph<char>graph;

	return 0;
}

