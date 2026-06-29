#include <iostream>

using namespace std;

template<typename KEY, typename VALUE>
class HashTable
{
private:
	struct Node
	{
		Node * next;
		KEY k;
		VALUE v;
	};

	struct Bucket
	{
		int count;
		Node* head;
	};

	int capacity;
	int size;
	Bucket* bucket;
public:
	HashTable()
	{
		size = 0;
		capacity = 8;

		bucket = new Bucket[capacity];

		for (int i = 0; i < capacity; i++)
		{
			bucket[i].head = nullptr;
			bucket[i].count = 0;
		}
	}

	template<typename KEY>
	unsigned int hash_function(KEY key)
	{
		return (unsigned int)key % capacity;
	}

	template<>
	unsigned int hash_function(const char* key)
	{
		unsigned int sum = 0;
		for (int i = 0; *key != '\0'; i++)
		{
			sum += key[i];
			key = key + 1;
		}
		return sum % capacity;
	}

	void insert(KEY key, VALUE value)
	{
		int hashIndex = hash_function(key);

		Node* newNode = new Node;

		newNode->k = key; 
		newNode->v = value;

		newNode->next = nullptr;

		if (bucket[hashIndex].count == 0)
		{
			bucket[hashIndex].head = newNode;
		}
		else
		{
			newNode->next = bucket[hashIndex].head;

			bucket[hashIndex].head = newNode;
		}

		bucket[hashIndex].count++;

		size++;
	}
	~HashTable()
	{
		for (int i = 0; i < capacity; i++)
		{
			Node* deleteNode = bucket[i].head;
			Node* nextNode = bucket[i].head;

			if (bucket[i].head == nullptr)
			{
				continue;
			}
			else
			{
				while (nextNode != nullptr)
				{
					nextNode = deleteNode->next;
					delete deleteNode;
				}
			}
		}
		delete[] bucket;
	}

};

int main()
{
	HashTable<const char *, int> hashTable;

	hashTable.insert("abc", 12);

	return 0;
}

