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

	void push(T data)
	{
		if (capacity <= 0)
		{
			resize(1);
		}
		else if(index >= capacity)
		{
			resize(capacity * 2);
		}
		container[index++] = data;

		int child = index - 1;
		int parent = (child - 1) / 2;
		
		while (child > 0)
		{
			if (container[parent] < container[child])
			{
				swap(container[parent], container[child]);
			}
			child = parent;
			parent = (child - 1) / 2;
		}
	}

	void pop()
	{
		if (index <= 0)
		{
			cout << "Priority queue is empty" << endl;
		}
		else
		{
			container[0] = container[--index];

			container[index] = NULL;

			int parent = 0;
			int child = parent * 2 + 1;

			while (child < index)
			{
				child = parent * 2 + 1;

				if (container[child] < container[child] + 1)
				{
					child++;
				}

				if (container[child] < container[parent])
				{
					break;
				}
				else
				{
					std::swap(container[parent], container[child]);
					parent = child;
				}
			}
		}
	}

	~PriorityQueue()
	{
		if (container != nullptr)
		{
			delete[] container;
		}
	}

	const T& top()
	{
		return container[0];
	}

	const int& size()
	{
		return index;
	}
	
	const bool& empty()
	{
		return index <= 0;
	}


};

int main()
{
	PriorityQueue<int>pri_queue;
	pri_queue.push(10);
	pri_queue.push(20);
	pri_queue.push(30);
	

	while (pri_queue.empty() == false)
	{
		cout << pri_queue.top() << endl;
		pri_queue.pop();
	}

	return 0;
}

