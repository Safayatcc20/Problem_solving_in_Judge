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
const long long N = 100010;
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
    int n ;
    cin >> n;
    vector<int>v(n);
    for(auto &x:v) cin >> x;
    
    /* vector<int> dp(N + 1, INT_MAX);
    dp[1] = 0;

    for (int i = 2; i <= n; ++i) {
        dp[i] = min(dp[i], dp[i - 1] + abs(v[i - 1] - v[i - 2]));
        if (i > 2) {
            dp[i] = min(dp[i], dp[i - 2] + abs(v[i - 1] - v[i - 3]));
        }
    }
    cout << dp[n] << sad; */
    // My own Solve problem same problem in leetcode
    //https://leetcode.com/problems/min-cost-climbing-stairs/submissions/1149280352/
    vector<int>dp(v.size());
    dp[0] = 0;
    dp[1] = abs(v[0] - v[1]) + dp[0];
    for(int i = 2 ; i< v.size()  ; i++){
        //dp[i] = min((dp[i- 1] - v[i]), abs(dp[i-2] - v[i]));
        dp[i] = min(abs(v[i-1] - v[i]) + dp[i-1] , abs(v[i] - v[i-2]) + dp[i-2]);
    }
    cout << dp[n-1] << sad;
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