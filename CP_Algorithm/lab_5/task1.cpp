
#include <bits/stdc++.h>
using namespace std;
const int mx = 1e6+5;
long long dp[mx];
long long fibo(long long n ){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(dp[n] != -1) return dp[n];
    dp[n] = fibo(n-1) + fibo(n-2);
    return dp[n];
}
int main()
{
    long long n ;
    cin >>  n;
    memset(dp , -1 , sizeof(dp));
    cout << fibo(n) << endl;
}