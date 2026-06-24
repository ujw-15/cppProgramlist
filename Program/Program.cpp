#include <iostream>

using namespace std;

template<typename T>
class PriorityQueue
{
private:
	int index;
	int capacity;
	T * container;
public:
	PriorityQueue()
	{
		index = 0;
		capacity = 0;

		container = nullptr;
	}

	void resize(int newSize)
	{
		capacity = newSize;

		T* temporary = new T[capacity];

		for (int i = 0; i < capacity; i++)
		{
			temporary[i] = NULL;
		}
		for (int i = 0; i < index; i++)
		{
			temporary[i] = container[i];
		}
		delete[] container;

		container = temporary;
	}
};

int main()
{
	PriorityQueue<int>pri_queue;
	pri_queue.resize(1);
	pri_queue.resize(2);
	pri_queue.resize(4);

	return 0;
}

