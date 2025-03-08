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
int book(int n  , int x ,vector<int>&price , vector<int>&page , vector<int>&dp){
    if(n <= 0) return 0;
    if(dp[n] != -1) return dp[n];
    if(x < price[n]){
        dp[n] = max(dp[n] , book(n-1 , x , price , page , dp));
    }
    else{
        dp[n] = max( page[n] + book(n-1 , x - price[n] , price , page , dp)  , book(n -1 ,  x  , price , page , dp));
    }
    return dp[n];
}
void solve(){
    int n , x;
    cin >> n >> x;
    vector<int>price(n) , page(n);
    for(auto &x:price) cin >> x;
    for(auto &x:page) cin >> x;
    vector<int>dp(x+1 , 0);
    for(int i = 0 ; i < n ; i++){
        for( int j = x; j >= price[i] ; j--){
            dp[j] = max( dp[j] , page[i]  + dp[j - price[i]]);
        }
    }
    cout << dp[x] << sad;
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