#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


const int M = 4;
const int N = 3;
int main()
{
	//fixed size
	int arr[3][2] = {
		{10,20},
		{30,40},
		{50,60}
	};

	//variable size
	int arr[M][N];

	//double pointer
	int **matrix_pointer;
	matrix_pointer = new int* [M];
	for (int i = 0; i < M; i++)
		matrix_pointer[i] = new int[N];

	//array of pointers
	int *matrix[M];
	for (int i = 0; i < M; i++)
		matrix[i] = new int[N];

	//array of vectors
	vector<int> matrix_vector_rows[M];
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			matrix_vector_rows[i].push_back(5);
		}
	}

	//vector of vectors
	vector<vector<int>> vector_matrix;
	for (int i = 0; i < M; i++)
	{
		vector<int> v;
		for (int j = 0; j < N; j++)
			v.push_back(10);
		vector_matrix.push_back(v);
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
