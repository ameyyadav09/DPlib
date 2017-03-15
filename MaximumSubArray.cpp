#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int ip, n, i;
long long max_sum, cur_sum;

//return the maximum contigous sub array on the basis of kadanee's algorithm, conplexity O(n)
long long contigous(int arr [], int n) {
    max_sum = INT_MIN;
    cur_sum = 0;
    for(i = 0; i < n;i++) {
        cur_sum = cur_sum + arr[i];
        if(cur_sum > max_sum)
            max_sum = cur_sum;
        if(cur_sum < 0)
            cur_sum = 0;
    }
    return max_sum;
}


//returns the maximum non-contigous subarray on the basis of kadanee's algorithm, complexity O(n)
long long noncontigous(int arr [] , int n) {
    cur_sum = arr[0];
    max_sum = arr[0];
    for (i = 1; i < n; i++) {
        cur_sum = max(cur_sum+arr[i], max(cur_sum, (long long) arr[i]));
        if(cur_sum > max_sum)
            max_sum = cur_sum;
        if(cur_sum < 0)
            cur_sum = arr[i];
    }
    return max_sum;
}
int main() {
    ios_base::sync_with_stdio (false);
    cin.tie(NULL);
    
    cin >> ip;
    while(ip) {
        cin >> n;
        int arr[n];
        i = 0;
        while(i < n) {
            cin >> arr[i++];
        }        
        cout << contigous(arr, n) << " " << noncontigous(arr, n) << "\n";
        ip--;
    }
    return 0;
}
