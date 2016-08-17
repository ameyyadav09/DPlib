#include<iostream>
using namespace std;

int brute_force(long long n, long long m) {
	for ( int i = 0; i < m; i++) {
		if (((long long)i*n)%m==1)
			return i;
		i++;
	}
}

int fast_pow(long long base, long long n, long long m) {
	if ( n == 0) {
		return 1;
	}
	if (n == 1) {
		return base;
	}
	cout <<","<< n<<","<<m<<endl;
	long long decr = fast_pow(base, n/2, m);
	cout << decr <<","<< n<<","<<m<<endl;
	if (n%2 == 0) {
		return (decr * decr)%m;
	}
	else {
		return (((decr*decr)%m)*base)%m;
	}
}

int main() {
	//a*x = 1 (%m) we need to find x.
	int a = 9, m = 11;
	cout << fast_pow(a,m-2,m);
	return 0;
}