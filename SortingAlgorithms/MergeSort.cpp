// divide and conquer
// continiously split the array in half until left with individual elements
// each pair of elements we sort
// then we merge the sorted pairs into a larger array
//and do so until we are left with one array

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 - r - m;

	//temp arrays
	int* L = new int[n1];
	int* R = new int[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0; // initial index of first subarray
	j = 0; // initial index of second subarray
	k = l; // initial index of merged subarray

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	//copy remaining elements of L, if any
	while (i < n1)
	{
		arr[k] = L[i];
		i++, k++;
	}
	// same for right
	while (j < n2)
	{
		arr[k] = R[j];
		j++, k++;
	}

	delete[] L;
	delete[] R;
}

void merge_sort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		merge_sort(arr, l, m);
		merge_sort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}