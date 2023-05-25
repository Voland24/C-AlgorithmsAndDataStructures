// heap is an ordered binary tree

// max heap is a heap where the parent is larger than its children

//we create a tree from the array
// then we create a max heap from the tree
// we get the root of the heap i.e. the max element
// and swap the max element and the last element of the unsorted part of array

// then we heapify the tree since it's no longer a heap
// and continue the process


void heapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i)
	{
		std::swap(arr[i], arr[largest]);
		heapfiy(arr, n, largest);
	}
}

void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		std::swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
		
}