// compare each two elements and sort them correctly
// the largest element will bubble towards the end and get to the end of the array
// repeat process until the end of the unsorted part until all elements are in correct position


void bubbleSort(int[] arr, int len)
{
	bool changed;

	len--;

	for (int i = 0; i < len; i++)
	{
		changed = false;
		for (int j = 0; j < len - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
				changed = true;
			}
		}

		if !changed
			return;
	}
}