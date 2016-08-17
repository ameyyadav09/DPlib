/* Dynamic Programming C/C++ implementation of LIS problem */
#include<iostream>
using namespace std;

/* lis() returns the length of the longest increasing
subsequence in arr[] of size n */
int LongestIncreasingSequence( int arr[], int n )
{
	int mem_array [n];
	int i = 0, j = 0;
	for (; i < n; i++)
		mem_array[i] = 1;
	for ( i = 1; i < n; i++) {
		for ( j = 0; j < i; j++) {
			if (arr[i] > arr[j] && mem_array[i] < mem_array[j]+1) {
				mem_array[i] = mem_array[j] + 1;
			}
		}
	}
	int max = 0;

	for (i = 0; i < n ; i++) {
		if (mem_array[i] > max)max = mem_array[i];
	}
	return max;
}

/* Driver program to test above function */
int main()
{
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Length of lis is: " << LongestIncreasingSequence( arr, n ) << endl; 
	return 0;
}
