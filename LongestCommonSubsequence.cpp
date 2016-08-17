#include<iostream>
#include<string>
using namespace std;

/* Utility function to get max of 2 integers */
int max(int a, int b) {
    return (a > b)? a : b;
}

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int LongestCommonSubsequence( string x, string y , int lx, int ly ) {
    int mem_arr [lx+1] [ly+1], i, j;

    for (i = 0; i <= lx; i++) {
        for ( j = 0; j <= ly; j++) {
            if (i == 0 || j == 0)
                mem_arr[i][j] = 0;
            else if (x[i-1] == y[j-1])
                mem_arr[i][j] = mem_arr[i-1][j-1] + 1;
            else
               mem_arr[i][j] = max (mem_arr[i-1][j], mem_arr[i][j-1]);
        }
    }
    return mem_arr[lx][ly];
}


/* Driver program to test above function */
int main() {
    int n = 6, m = 7;
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    cout << "Length of LCS is " << LongestCommonSubsequence(X, Y, n, m) << endl ;

    return 0;
}