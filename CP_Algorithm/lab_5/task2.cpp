
#include <bits/stdc++.h>
using namespace std;
long long t = 1;
const int mx = 1e3+5;
long long dp[mx][mx];
long long cal_nCr(long long n , long long r){
    if( r == 0 ) return 1;
    if( r == n ) return 1;
    if(dp[n][r] != 0) return dp[n][r];
    dp[n][r] = cal_nCr(n-1 ,r) + cal_nCr(n-1 , r-1);
    return dp[n][r];
}
int main()
{
    long long n , r;
    cin >> n >> r;
    memset(dp , 0 , sizeof(dp));
    cout << cal_nCr(n , r) << endl;
}