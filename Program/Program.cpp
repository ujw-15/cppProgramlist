#include <iostream>

using namespace std;
template <typename T>
class Tree
{

private:
	struct Node
	{
		T data = 0;
		Node* left;
		Node* right;

		Node(T data)
		{
			this->data = data;

			left = nullptr;
			right = nullptr;

		}
		
	};

	Node* root;
public:
	Tree()
	{
		root == nullptr;
	}

	void insert(T data)
	{
		if (root == nullptr)
		{
			root = new Node(data);
		}
		else
		{
			Node* currentNode = root;

			while (true)
			{
				if (currentNode->data == data)
				{
					return;
				}

				if (data < currentNode->data)
				{
					if (currentNode->left == nullptr)
					{
						currentNode->left = new Node(data);

						break;
					}
					else
					{
						currentNode = currentNode->left;
					}
				}
				else if (data > currentNode->data)
				{
					if (currentNode->right == nullptr)
					{
						currentNode->right = new Node(data);

						break;
					}
					else
					{
						currentNode = currentNode->right;
					}
				}
				else
				{
					break;
				}
			}
		}
	}

	void inorder(Node* root)
	{
		while (root != nullptr)
		{
			if (root == nullptr)
			{
				root = root->data;
				return root;
				root = root->right;
			}
			else
			{
				root = root->left;
			}

		}
	}
};

int main()
{
	Tree<int>tree;

	tree.insert(10);
	tree.insert(20);
	tree.insert(30);
	tree.insert(40);

	return 0;
}

