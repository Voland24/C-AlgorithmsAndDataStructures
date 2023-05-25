
// arr needs to be sorted in order to work

int jumpSearch(int arr[], int x, int n)
{
	// step to take
	int step = sqrt(n);

	int prev = 0;
	while (arr[min(step, n) - 1] < x)
	{
		prev = step;
		step += sqrt(n);
		if (prev >= n)
			return -1;
	}

	// now do a linear search for x staring at prev
	while (arr[prev] < x)
	{
		prev++;
		if (prev == min(step, n))
			return -1;
	}

	if (arr[prev] == x)
		return prev;

	return -1;
}