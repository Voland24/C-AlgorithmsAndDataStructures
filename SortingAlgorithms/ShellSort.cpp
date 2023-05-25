// we go through the array with inital step of k = n / 2
// we take 0 and 6, 1 and 7 etc and compare. The smaller one goes towards the front
// we take all combination, front and back, and then decrease k by /2.


// n = 12
// i = 6


void ShellSort(int a[], int n)
{
	int i, j, k, temp;
	for (int i = n / 2; i > 0; i = i / 2)
	{
		for (j = i; j < n; j++)
		{
			for (k = j - i; k >= 0; k = k - i)
			{
				if (a[k + i] >= a[k])
					break;
				else
				{
					temp = a[k];
					a[k] = a[k + i];
					a[k + i] = temp;
				}
			}
		}
	}
}