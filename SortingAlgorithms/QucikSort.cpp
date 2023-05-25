// choose pivot, good rule is median of three
// sort first, middle and last element of array and choose the sorted middle one as pivot
// swap pivot and the last element
// pick first element from left larger than pivot
// pick first element from right smaller than pivot
// swap these two elements
// repeat the process until the item on the left has a higher index than the right one
// swap back the last element i.e. our pivot with the last chosen item from left
// call quicksort recursively on the two partitions made by the pivot

#include <vector>

void quick_sort(std::vector<int>&, size_t, size_t);
int partition(std:vector<int>&, size_t, size_t);

void quick_sort(std::vector<int>& arr, size_t start, size_t end)
{
	if (start < end)
	{
		int pivot = partition(arr, start, end);
		quick_sort(arr, start, pivot);
		quick_sort(arr, pivot + 1, end);
	}
}

int partition(std::vector<int>& arr, size_t start, size_t end)
{
	int x = arr[start];
	int i = start;
	for (size_t j = start + 1; j < end; j++)
	{
		if (arr[j] <= x)
		{
			i++;
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i], arr[start]);
	return i;
}