#include <iostream>
#include <string>
#include <climits>
#include <stdexcept>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

long n, m;
int i;

long combines2(long arr[], long n, long m) {
	long res[m+1][n+1];
	for(i = 0;i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			res[i][j] = 0;
		}
	}
	for(i = 0; i <= m; i++) {
		res[i][0] = 1;
	}

	for(i = 1;i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if(j < arr[i-1])
				res[i][j] = res[i-1][j];
			else
				res[i][j] = res[i-1][j] + res[i][j-arr[i-1]];
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}
	cout << res[m][n];
}
long combines(long arr[], long n, long m) {
	long long res [n+1];
	for(i = 0; i <= n; i++) {
		res[i] = 0;
	}
	res[0] = 1;
	for(i = 0; i < m; i++) {
		for (int j = arr[i]; j <= n; j++) {
			res[j] = res[j] + res[j-arr[i]];
		}
	}
	return res[n];
}

int main() {
	ios_base::sync_with_stdio (false);
	cin.tie(NULL);

	cin >> n >> m;
	i = 0;
	long arr[m];
	while(i < m) {
		cin >> arr[i++];
	}

	cout << combines(arr, n, m) << "\n";
	combines2(arr, n, m);
	return 0;
}