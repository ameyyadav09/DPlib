#include <iostream>
#include <string>
#include <climits>
#include <stdexcept>
#include <set>
#include <cmath>
using namespace std;

int n, val, i, ip;
long long DEN, max_sum, cur_sum;
int main() {
	ios_base::sync_with_stdio (false);
	cin.tie(NULL);

	cin >> ip;
	while(ip) {
		cin >> n >> DEN;
		i = 0;
		int arr[n];
		while(i < n) {
			cin >> val;
			arr[i++] = val;
		}
		max_sum = 0;
		cur_sum = 0;
		for( i = 0; i < n; i++) {
			cur_sum = max((cur_sum+arr[i])%DEN, max(cur_sum, arr[i]%DEN))%DEN;
			if(cur_sum > max_sum)
				max_sum = cur_sum;
			else if(cur_sum < 0)
				cur_sum = 0;
		}
		cout << max_sum << "\n";
		ip--;
	}
	return 0;
}

// #include <stdio.h>
 
// void contiguousSubArrayWithLargestsum(int a[], int size){
 
//     int startIndex = 0, endIndex = 0;
//     int index;
//     int currStartIndex = 0;
 
//     int maxSum = 0;
//     int currentSum = 0;

 //     for(index = 0 ; index < size; index++){
//         currentSum  = (currentSum + a[index])%7;
//         // case 1 : When ith element can be included
//         // Change the end index and also update the start index.
//         if(currentSum > maxSum){
//             maxSum = currentSum;
//             endIndex = index;
//             startIndex = currStartIndex;
//         }
//         /*case 2 : When ith index cannot be included and 
//         we need to start with i+1 index. till now our max sum
//         and start and end index of that sum remain same */
//         if(currentSum < 0){
//             currStartIndex = index + 1;
//             currentSum = 0;
//         }
//     }
//     printf("\nMaximum Sum : %d", maxSum);
//     printf("\nBetween (%d, %d)", startIndex, endIndex);
// }
 
// //Driver program
// int main() {
 
//    int intArr[] = {3,2,0,7,-5};
//    int size = sizeof(intArr)/sizeof(intArr[0]);
//    contiguousSubArrayWithLargestsum(intArr, size);
 
//     return 0;
// }