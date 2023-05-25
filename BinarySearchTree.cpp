#include <iostream>

#include <iostream>

using namespace std;

struct btNode
{
	int data;
	btNode* left;
	btNode* right;
};

void bst_insert(btNode*& bst_root, int anInt)
{
	if (bst_root == 0) // list is empty
	{
		btNode* newNode = new btNode;
		newNode->data = anInt;
		newNode->left = 0;
		newNode->right = 0;

		bst_root = newNode;
		return;
	}

	//list not empty

	btNode* marker = new btNode; //for traversal pointer
	marker = bst_root; //start at the specified place
	while (marker != 0) //while not at end
	{
		if (marker->data == anInt) //duplicate found
		{
			marker->data = anInt;
			return;
		}

		if (marker->data > anInt)
		{
			if (marker->left != 0) //if left is not null
			{
				marker = marker->left; //go left
			}

			else
			{
				//it's empty, populate
				btNode* newNode = new btNode;
				newNode->data = anInt;
				newNode->left = 0;
				newNode->right = 0;

				marker->left = newNode; // attach the new node
				return;
			}
		}

		if (marker->data < anInt)
		{
			if (marker->right != 0)
				marker = marker->right;
			else
			{
				btNode* newNode = new btNode;
				newNode->data = anInt;
				newNode->left = 0;
				newNode->right = 0;

				marker->right = newNode; // attach the new node
				return;
			}
		}
	}
}


bool bst_remove(btNode*& bst_root, int anInt)
{
	if (bst_root == 0) //empty tree
		return false;

	if (bst_root->data > anInt) // the val is smaller, so search on the left of the current Node
		return bst_remove(bst_root->left, anInt);

	if (bst_root->data < anInt)
		return bst_remove(bst_root->right, anInt); //opposite, go right for the target val

	if (bst_root->data == anInt)
	{
		if (bst_root->left == 0) //no left node
		{
			btNode* temp = bst_root;
			bst_root = bst_root->right;
			delete temp;
			return true;
		}

		bst_remove_max(bst_root->left, bst_root->data);
		return true;
	}

	return false; // no val found
}

void bst_remove_max(btNode*& bst_root, int& info)
{
	if (bst_root->right != 0) // right node still occupied
	{
		return bst_remove_max(bst_root->right, info);
	}

	btNode* tempNode = new btNode;
	tempNode = 0;

	btNode* marker = new btNode;
	marker = bst_root;

	if (bst_root->right == 0)
	{
		info = bst_root->data; // get info in the node
		tempNode = marker;
		bst_root = bst_root->left;
		delete tempNode;
	}
}