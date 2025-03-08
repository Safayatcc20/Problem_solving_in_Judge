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
const int mod = 1e9 + 7;
int puredp(int i , int j , vector<vector<int>>&dp , vector<vector<int>>&grid){
    if(i < 0 or j < 0 ) return 0;
    if(grid[i][j] == 0) return 0;
    if(i == 0 and j == 0) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    dp[i][j] = (puredp(i , j - 1 , dp , grid) + puredp(i - 1 , j , dp , grid))  % mod;
    return dp[i][j]  % mod;
}
int uniquePaths(int n, int m, vector<vector<int>> &grid) {
    vector<vector<int>>dp(n+1 , vector<int>(m+ 1 , -1));
    return  puredp(n-1,  m- 1, dp , grid);
}
void solve(){
    int n , m ;
    cin >> n >> m;
    vector<vector<int>>grid(n , vector<int>(m));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ;j < m ; j++){
            cin >> grid[i][j];
        }
    }
    /* for(int i = 0 ; i < n ; i++){
        for(int j = 0 ;j < m ; j++){
            cout << grid[i][j];
        }
        cout << sad;
    } */
    cout << uniquePaths(n , m , grid) << sad;
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