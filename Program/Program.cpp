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
	unsigned int hasf_function(KEY key)
	{
		return (unsigned int)key % capacity;
	}

	template<>
	unsigned int hash_function(const char* key)
	{
		unsigned int sum = 0;
		for (int i = 0; i * key != '\0'; i++)
		{
			sum += key[i];
			key = key + 1;
		}
		return sum % capacity;
	}

};

int main()
{
	HashTable<int, int> hashTable;

	cout << hashTable.hasf_function(3129) << endl;
	cout << hashTable.hasf_function(-3) << endl;

	return 0;
}

