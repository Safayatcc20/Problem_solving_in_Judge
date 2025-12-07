 
 /***** Bismillahir Rahmanir Rahim *****/
 
#include <bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T> using oset = tree<T , null_type , less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/// order_of_key(x) returns number of elements strictly less than x
/// find_by_order(x) return x th element of the set (0 based index)
///less dile choto theke boro sajano
///less equal dile multiset er moto kaj kore
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
// if c % gcd( a , b)  == 0 then solution exist otherwise not
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
// Euler totient function for single call
int phi(int n){
  int ans = n;
  for(int i = 2; i * i <= n ;i++){ 
   if(n % i == 0){
       ans /= i;
       ans *= (i-1);
       while(n % i== 0) n/= i;
   }
  }
  if(n > 1) ans /= n , ans *= (n - 1);
  return ans;
}
//Euler totient preprocessing(from 1 to n ) in O(nloglog(n))
vector<int>phai(1e7+10);
void init(){
// here check the problem requirement
     int maxn = 1e7+10;
     for(int i = 1; i <= maxn; i++){
       phai[i] = i;
     }
     for(int i = 2; i<= maxn; i++){
       if(phai[i] == i){
         for(int j = i; j <= maxn; j+=i){
           phai[j]/=i; phai[j] *= (i-1);
         }
       }
     }
     // here is the prefix sum of phai function
     // for(int i = 1; i <= maxn; i++){
     //     phai[i] += phai[i-1];
     // }
}
// using recursive dp
// To make use of recursive calls, this
// function must return two things:
// 1) Length of LIS ending with element
// arr[n-1].
// We use max_ending_here for this purpose
// Overall maximum as the LIS may end with
// an element before arr[n-1] max_ref is
// used this purpose.
// The value of LIS of full array of size
// n is stored in *max_ref which is
// our final result
int f(int idx, int prev_idx, int n, vector<int>&v,
      vector<vector<int> >& dp)
{
    if (idx == n) {
        return 0;
    }
 
    if (dp[idx][prev_idx + 1] != -1) {
        return dp[idx][prev_idx + 1];
    }
 
    int notTake = 0 + f(idx + 1, prev_idx, n, v, dp);
    int take = INT_MIN;
    if (prev_idx == -1 || v[idx] == v[prev_idx]) {
        take = 1 + f(idx + 1, idx, n, v, dp);
    }
 
    return dp[idx][prev_idx + 1] = max(take, notTake);
}
 
// Function to find length of
// longest increasing subsequence
int longestSubsequence(int n, vector<int>&v)
{
    vector<vector<int> > dp(n + 1, vector<int>(n + 1, -1));
    return f(0, -1, n, v, dp);
}
// using iterative LIS dp
// int lis(vector<int>&v) {
//     int n = v.size();
//     vector<int> d(n, 1);
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < i; j++) {
//             if (v[j] < v[i])
//                 d[i] = max(d[i], d[j] + 1);
//         }
//     }

//     int ans = d[0];
//     for (int i = 1; i < n; i++) {
//         ans = max(ans, d[i]);
//     }
//     return ans;
// }
//O(nlog(n)) Solution for longest legth
int lis(vector<int> const& v) {
    int n = v.size();
    const int INF = 1e9;
    vector<int> dp(n+1, 0);

    vector<vector<int>>pos(n+1);

    for(int i = 0 ; i < n ;i++){
        pos[v[i]].push_back(i);
    }
    
    for (int i = n- 1; i >= 0; i--) {
        dp[i] = dp[i+1];
        int l = lower_bound(pos[v[i]].begin(), pos[v[i]].end(), i) - pos[v[i]].begin();
        
        if(l + v[i]   - 1 < pos[v[i]].size()){
            int last = pos[v[i]][l + v[i]   - 1];
            dp[i] = max(dp[i] , v[i] + dp[last+1]);
        }
        // cout << dp[i] <<" "<< l+v[i] - 1 <<" "<<  l << " "<< pos[v[i]].size() << sad;
    }

    return dp[0];
}
void solve(){
    int n;
    cin >> n;
    vector<int>v(n);
    for(auto &x:v) cin >> x;
    int ans = lis( v);
    cout << ans << sad;

}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}