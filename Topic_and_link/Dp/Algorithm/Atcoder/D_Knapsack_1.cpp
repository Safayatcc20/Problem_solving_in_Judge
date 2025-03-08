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
// Linear Diophantine Equation ax + by = c;
//solution by using  Extended Euclidean algorithm one solution
int extgcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
int dp[101][100000+10];
int knapsack(int ind,vector<pair<int , int>>&v , int w ){
    if(ind  < 0) return 0;
    if(dp[ind][w] != -1) return dp[ind][w];
    if(v[ind].first > w){
        dp[ind][w] = knapsack(ind-1 , v , w);
        
    }
    else dp[ind][w] = max((knapsack(ind-1 , v , w - v[ind].first) + v[ind].second ) , knapsack(ind - 1, v , w));
    return dp[ind][w];
}
void solve(){
    int n , w;
    cin >>n >> w;
    vector<pair<int , int>>v(n);
    memset(dp , 0 , sizeof(dp));
    for(auto &x:v) cin >> x.first >> x.second;
    //cout << knapsack(n - 1, v , w) << sad;
    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= w ; j++){
            if(v[i-1].first > j){
                dp[i][j] = dp[i-1][j]; 
            }
            else{
                dp[i][j] = max(dp[i-1][j] , v[i-1].second + dp[i-1][j-v[i-1].first]);
            }
        }
    }
    cout << dp[n][w] << sad;
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