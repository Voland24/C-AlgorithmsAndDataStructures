// start from left
// work from the chosen element, look through all of the elements on its left and insert the chosen element 
//in the correct position with respect to the elements on its left


void insertionSort(int a[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}