#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
	int data;
	Node* right;
	Node* left;

	Node(int d) {
		data = d;
		left = nullptr;
		right = nullptr;
	}
};

//INorder i.e. LEFT - ROOT - RIGHT

void inorder(Node* root)
{
	if (root == nullptr)
		return;
	inorder(root->left);
	cout << root->data << endl;
	inorder(root->right);
}

//PREorder i.e. ROOT- LEFT- RIGHT

void preorder(Node* root)
{
	if (root == nullptr)
		return;

	cout << root->data << endl;
	preorder(root->left);
	preorder(root->right);
}

//POSTorder i.e. LEFT - RIGHT - ROOT

void postorder(Node* root)
{
	if (root == nullptr)
		return;

	postorder(root->left);
	postorder(root->right);
	cout << root->data << endl;
	
}


//HEIGHT of tree

int height(Node* root)
{
	if (root == nullptr)
		return 0;

	return (1 + max(height(root->left), height(root->right)));
}

//print nodes at k distance

void printNodes(Node* root, int k)
{
	if (root == nullptr)
		return;

	if (k == 0)
		cout << root->data << endl;
	else
	{
		printNodes(root->left, k - 1);
		printNodes(root->right, k - 1);
	}
}


// level order i.e. line by line 

void levelOrder(Node* root)
{
	if (root == nullptr)
		return;

	queue<Node*> q;
	q.push(root);

	while (q.empty() == false)
	{
		Node* curr = q.front();
		q.pop();

		cout << curr->data << endl;

		if (curr->left)
			q.push(curr->left);
		if (curr->right)
			q.push(curr->right);
	}
}

//size of tree

int sizeOfTree(Node* root)
{
	if (root == nullptr)
		return 0;

	return (1 + sizeOfTree(root->left) + sizeOfTree(root->right));
}

//check for balanced tree
// The height difference for left and right subtree for every node should not exceed 1
int balancedTree(Node* root)
{
	if (root == nullptr)
		return true;

	int left_height = balancedTree(root->left);
	if (left_height == -1)
		return -1;

	int right_height = balancedTree(root->right);
	if (right_height == -1)
		return -1;

	if (abs(left_height - right_height) > 1)
		return -1;
	
	return max(left_height, right_height) + 1;
}