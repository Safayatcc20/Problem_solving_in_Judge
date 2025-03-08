#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define int long long
long long t = 1;
const int mod = 1000000007;
int n ;
int grid(int i , int j , vector<vector<int>>&dp , vector<string>&v){
    if(i >= n or j >= n) return 0;
    if(i == n-1 and j == n-1){
        if(v[i][j] == '*') dp[i][j] = 0;
        else dp[i][j] = 1;
        return dp[i][j];
    } 
    if(v[i][j] == '*') return dp[i][j] = 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(i < n-1){
        if(dp[i][j] == -1) dp[i][j] = 0;
        dp[i][j] = (dp[i][j] + grid(i+1 , j , dp , v)) %mod;
    }
    if(j < n-1){
        if(dp[i][j] == -1) dp[i][j] = 0;
        dp[i][j] = (dp[i][j] + grid(i , j+1 , dp , v)) % mod;
    }
    return dp[i][j] % mod;
}
void solve(){
    cin >> n;
    vector<string> v(n);
    for(int i =  0 ; i < n ; i++){
        cin >> v[i];
        
    }
    // state dp[i][j] = num. of ways ( i , j) to (n-1 , m-1);
    // transition dp[i][j] = dp[i+1][j](down) + dp[i][j+1](right);
    //base case n-1,m-1 has obstacle way is = 0 else 1
    // final is dp[0][0]
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << grid(0 , 0 , dp , v) << sad;
    /* if(v[n-1][n-1] == '*') dp[n-1][n-1] = 0;
    else dp[n-1][n-1] = 1;
    for(int i = n - 1; i >= 0 ; i--){
        for(int j = n - 1; j >= 0 ; j--){
            if(i == n-1 and j == n-1) continue;
            if(v[i][j] == '*') dp[i][j] = 0;
            else {
                if(i < n-1) dp[i][j] = dp[i+1][j] % mod;
                if(j < n-1) dp[i][j] = (dp[i][j+1] + dp[i][j]) % mod;
            }
        }
    }
    cout << dp[0][0] << sad; */
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
