#include <iostream>
using namespace std;

class MinHeap {
	int *arr;
	int size;
	int capacity;

	MinHeap(int c)
	{
		arr = new int[c];
		size = 0;
		capacity = c;
	}

	int left(int i)
	{
		return arr[2 * i + 1];
	}
	int right(int i)
	{
		return arr[2 * i + 2];
	}

	int parent(int i)
	{
		return (i - 1) / 2;
	}

	void insert(int x) // O(logn)
	{
		if (size == capacity)
			return;

		size++;
		arr[size - 1] = x;

		int i = size - 1; //last index, the newly inserted value

		while (i > 0 and arr[parent(i)] > arr[i])
		{
			swap(arr[parent(i)], arr[i]);
			i = parent(i);
		}
	}
};