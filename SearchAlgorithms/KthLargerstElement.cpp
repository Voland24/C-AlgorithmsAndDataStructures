#include <vector>
#include <queue>

// find kth largest element in least ammount of time i.e. O(nlogn)

int kthLargest(vector<int> arr, int n, int k)
{
	priority_queue<int, vector<int>, greater<int>> pq;
	// put first k elements into pq
	for (int i = 0; i < k; i++)
		pq.push(arr[i]);
	// the remainding n - k elements now go in
	for (int i = k; i < n; i++)
	{
		if (arr[i] > pq.top())
		{
			pq.pop();
			pq.push(arr[i]);
		}
	}
	return pq.top();
}