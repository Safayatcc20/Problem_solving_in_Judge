/*
 **** Bismillahir Rahmanir Rahim ****
 */
 
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define minusone cout << "-1" << '\n'
#define int long long
long long t = 1;
void solve(){
    int n ;
    cin >> n;
    vector<int>a(n) , b(n) , c(n);
    for(int i = 0 ; i < n ;i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    vector<vector<int>>dp(n + 1 , vector<int>(3));
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];
    for(int i  = 1; i < n ;i++){
        dp[i][0] = a[i] + max(dp[i-1][1] , dp[i-1][2]);
        dp[i][1] = b[i] + max(dp[i-1][0] , dp[i-1][2]);
        dp[i][2] = c[i] + max(dp[i-1][1] , dp[i-1][0]);
    }
    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << sad;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}