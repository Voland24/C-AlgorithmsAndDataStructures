using namespace std;


// the vector has to be sorted prior to the search

// iterative case, O(logn) time
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


// recursive case, space and time is O(logn)

int recursiveBinarySearch(vector<int> nums, int low, int high, int target)
{
	if (low > high)
		return -1;

	int mid = (low + high) / 2;

	if (nums[mid] == target)
		return mid;
	if (nums[mid] > target)
		return recursiveBinarySearch(nums, low, mid - 1, target);
	else
		return recursiveBinarySearch(nums, mid + 1, high, target);

}