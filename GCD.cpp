#include <iostream>
#include <tuple>
#include <vector>
#include <string>
using namespace std;
string st1, st2;

//returns GCD
long long gcd (long long a, long long b) {
	while(a&&b)a>b?a%=b:b%=a;
	return a+b;
}

//lcm
long long lcm(long long a, long long b) {
	return (a*b)/gcd(a, b);
}

int main(){
	cout << lcm(9, 15)<< endl;
	return 0;
}
