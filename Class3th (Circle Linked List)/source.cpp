#include <iostream>

using namespace std;

template<typename T>
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
			newNode->next = newNode;
		}
		else
		{
			newNode->next = head->next;
			head->next = newNode;
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
			Node* deleteNode = head->next;

			if (head == head->next)
			{
				head = nullptr;
			}
			else
			{
				head->next = deleteNode->next;
			}
			delete deleteNode;

			size--;
		}
	}

	void push_back(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		if (head == nullptr)
		{
			head = newNode;
			newNode->next = newNode;
		}
		else
		{
			newNode->next = head->next;
			head->next = newNode;
			head = newNode;
		}
		size++;
	}

	void pop_back()
	{
		if (head == nullptr)
		{
			cout << "Linked list is empty" << endl;
		}
		else
		{
			Node* deleteNode = head;
			Node* currentNode = head;
			if (head == head->next)
			{
				head = nullptr;
			}
			else
			{
				for (int i = 0; i < size - 1; i++)
				{
					currentNode = currentNode->next;
				}
				currentNode->next = head->next;
				head = currentNode;
			}
			delete deleteNode;
		}
	}

	const bool& empty()
	{
		return head == nullptr;
	}

	~List()
	{
		while (head != nullptr)
		{
			pop_front();
		}
	}

};

int main()
{
	List<int>list;
	list.push_front(10);
	list.push_back(20);
	list.push_back(20);
	list.pop_front();
	list.pop_front();
	list.pop_back();

	return 0;
}

