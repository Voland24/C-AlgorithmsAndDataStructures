#include <iostream>
#include <cstdio>

using namespace std;

Node *top = nullptr;
int max_size = 100;

class Node {
public:
	int data;
	Node* next;
	Node():data(0), next(nullptr) {}
	Node( int data, Node* next): data(data), next(next) {
	}
};

void linkedListTraverse(Node* ptr)
{
	while (ptr != nullptr)
	{
		printf("Element is : %d\n", ptr->data);
		ptr = ptr->next;
	}
}

int isEmpty(Node* top)
{
	if (top == nullptr)
		return 1;
	else
		return 0;
}

bool isFull( Node* top)
{	
	int count = 0;
	while (top != nullptr) {
		count++;
		top = top->next;
	}
	return count == max_size;
}

Node* push( Node* top, int data)
{
	if (isFull(top))
	{
		printf("Overflow!\n");
	}
	else
	{
		Node* n = new Node();
		n->data = data;
		n->next = top;
		top = n;
		return top;
	}
}

int pop(Node* tp)
{
	if (isEmpty(tp))
	{	
		printf("Underflow!");
		return 0;
	}
	else
	{
		Node* n = tp;
		top = tp->next;
		int x = n->data;
		delete n;
		return x;
	}
}

int peek(int pos)
{
	Node* ptr = top;
	for (int i = 0; (i < pos - 1 && ptr != nullptr); i++)
	{
		ptr = ptr->next;
	}
	if (ptr != nullptr)
		return ptr->data;
	else
		return -1;
}
