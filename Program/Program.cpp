#include <iostream>

using namespace std;

template<typename T> 
class List
{
private:
	struct Node
	{
		T data;
		Node* previous;
		Node* next;
	};
	int size;
	Node* head;
	Node* tail;

public:
	List()
	{
		size = 0;
		head = nullptr;
		tail = nullptr;
	}

	void push_front(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;
		newNode->previous = nullptr;

		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			head->previous = newNode; // <-
			newNode->next = head; // ->

			head = newNode; // 이동
		}
		size++;
	}
};

int main()
{
	List<int>list;
	list.push_front(10);
	list.push_front(20);
	return 0;
}

