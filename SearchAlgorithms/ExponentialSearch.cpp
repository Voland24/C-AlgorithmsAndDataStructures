int binarySearch(vector<int> nums, int target)
{
	int n = nums.size();
	int low = 0;
	int high = n - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (nums[mid] == target)
			return mid;
		else if (nums[mid] > target)
			high = mid - 1;
		else
			low = mid + 1;

	}

	return -1;
}

int exponentialSearch(vector<int> nums, int n, int x)
{
	if (nums[0] == x)
		return 0;
	int i = 1;
	while (i < n && nums[i] <= x)
		i = i * 2;

	return binarySearch(nums, i / 2, min(i, n), x);
}