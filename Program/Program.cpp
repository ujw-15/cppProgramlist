#include <iostream>

using namespace std;

template <typename T>
class List
{
private:
	struct Node
	{
		T data;
		Node* next;
	};

	Node* head;
	int size;

public:
	List()
	{
		head = nullptr;
		size = 0;
	}

	void push_front(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;

		if (head == nullptr)
		{
			head = newNode;
			newNode->next = nullptr;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
		size++;
	}

	void pop_front()
	{
		if (head == nullptr)
		{
			cout << "Linked list is empty" << endl;
		}
		else
		{
			Node* deleteNode = head;
			head = deleteNode->next;

			delete deleteNode;
			size--;
		}
	}

	void push_back(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;
		if (head == nullptr)
		{
			head = newNode;
		}
		else
		{
			Node* currentNode = head;
			while (currentNode->next != nullptr)
			{
				currentNode = currentNode->next;
			}
			currentNode->next = newNode;
		}
		size++;
	}

};

int main()
{
	List<int> list;

	list.push_front(10);
	list.push_front(5);
	list.pop_front();
	list.pop_front();
	list.pop_front();

	return 0;
}

