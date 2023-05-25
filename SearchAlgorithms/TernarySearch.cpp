// array is sorted, we move from two different position and search

// mid1 = 1 + (r - 1) / 3;
// mid2 = r - (r -1) / 3;


int ternarySearch(int arr[], int left, int right, int target)
{
	if (r < 1)
		return -1;

	int step = (r - 1) / 3;
	int mid1 = 1 + step;
	int mid2 = r - step;

	if (arr[mid1] == target)
		return mid1;
	if (arr[mid2] == target)
		return mid2;
	if (target < arr[mid1])
		return ternarySearch(arr, left, mid1 - 1, target);
	if (target > arr[mid2])
		return ternarySearch(arr, mid2 + 1, right, target);

}