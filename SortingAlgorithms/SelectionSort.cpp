

void selectionSort(int arr[], int n)
{
	int i, j, , min_ind;
	for (i = 0; i < n - 1; i++)
	{
		min_ind = i;
		for (j = i + 1; j < n; j++)
			if (arr[min_ind] > arr[j])
				min_ind = j;
		int temp = arr[min_ind];
		arr[min_ind] = arr[i];
		arr[i] = temp;

	}
}