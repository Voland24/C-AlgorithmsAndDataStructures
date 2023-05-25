int interpolationSearch(int arr[], int n, int x)
{
	// if x is present in arr, returns index, else returns -1

	int low = 0;
	int high = (n - 1);

	// since arr is sorted, x must be in range between low and high
	while (low <= high && x >= arr[low] && x <= arr[high])
	{
		if (low == high)
		{
			if (arr[low] == x)
				return low;
			return -1;
		}

		// we are probing, i.e. guessing where our target value is
		// works best for uniformly distributed data

		int pos = low + (((double)(high - low) / (arr[high - arr[low])) * (x - arr[low]));

		if (arr[pos] == x)
			return pos;

		if (arr[pos] < x)
			low = pos + 1;
		else
			high = pos - 1;
	}

	return -1;
}