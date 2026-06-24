#include <iostream>

#define SIZE 5

using namespace std;

template<typename T>
class Queue
{
private:
	T container[SIZE];
	int m_rear;
	int m_front;
public:
	Queue()
	{
		m_rear = 0;
		m_front = 0;
		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}
	}

	void push(T data)
	{
		if (m_rear >= SIZE)
		{
			cout << "linear queue overflow" << endl;
		}
		else
		{
			container[m_rear++] = data;
		}
	}

	void pop()
	{
		if (m_front == m_rear)
		{
			cout << "linear queue is empty" << endl;
		}
		else
		{
			container[m_front++] = NULL;
		}
	}

	const bool& empty()
	{
		return m_front == m_rear;
	}

	const int& size()
	{
		return m_rear - m_front;
	}

	const T& front()
	{
		return container[m_front];
	}
};

int main()
{
	Queue<int>queue;
	queue.push(10);
	queue.push(20);
	queue.push(30);
	queue.push(40);
	queue.push(50);

	while (queue.empty() == false)
	{
		cout << queue.front() << endl;
		queue.pop();
	}

	return 0;
}

