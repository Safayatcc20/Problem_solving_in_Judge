/*
 **** Bismillahir Rahmanir Rahim ****
 */
 
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define int long long
long long t = 1;
constexpr bool multiple_test_cases = 1;
long long gcd(long long x, long long y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
long long lcm(long long x, long long y)
{
    return ((x * y) / gcd(x, y));
}
const long long N = 10000;
long long prime[N];
long long fact(long long n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}
long long findXor(long long n){//reming: function calling findXor(sending value - 1);
    long long rest = n % 4;
    if(rest == 0) return n;
    if(rest == 1) return 1;
    if(rest == 2) return n+1;
    if(rest == 3) return 0;
}
void solve(){
    int n ,  m ;
    cin >> n >> m;
    vector<int>v(n);
    for(auto &x:v) cin >> x;
    int mod = 1e9+7;
    vector<vector<int>>dp(n , vector<int>(m+1 , 0)) , nv(n , vector<int>(m+1 , 0));
    if(v[0] != 0){
        dp[0][v[0]] = 1;
    }
    else{
        for(int i = 1; i <= m ;i++){ 
            dp[0][i] = 1;
        }
    }
    for(int i = 1; i < n ;i++){
        if(v[i] == 0){
            for(int j = 1;j <= m;j++){
                if(j  - 1 >= 1){
                    dp[i][j] = (dp[i][j] + dp[i-1][j-1] )% mod;
                }
                dp[i][j] = (dp[i][j]+ dp[i-1][j]) % mod;
                if(j + 1 <= m ){
                    dp[i][j] = (dp[i][j]  + dp[i-1][j+1]) % mod;
                }
            }
        }
        else{
            if(v[i]  - 1 >= 1){
                dp[i][v[i]] = (dp[i][v[i]] + dp[i-1][v[i]-1] )% mod;
            }
            dp[i][v[i]] = (dp[i][v[i]]+ dp[i-1][v[i]]) % mod;
            if(v[i] + 1 <= m ){
                dp[i][v[i]] = (dp[i][v[i]]  + dp[i-1][v[i]+1]) % mod;
            }

            
        }
    }
    int ans = 0 ;
    /* for(int i = 0; i < n ;i++){
        for(int j = 0 ;j <= m;j++){
            cout << dp[i][j] << " ";
        }cout << sad;
    } */
    for(int i = 1; i <= m ;i++){
        //cout << dp[n-1][i] << " ";
        ans  = (ans + dp[n-1][i])  % mod;
    }
    cout <<ans << sad;
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