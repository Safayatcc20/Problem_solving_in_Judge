 
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
const int mod = 998244353;
const int N = 2e5+10;
int dp[N][2][2][2];
int fun(vector<int>&v,int ind , int one , int two , int thr){
    if(ind >= v.size() ) {
        if(one and two and thr) return 1;
        return 0;
    }
    int &ans = dp[ind][one][two][thr];
    if(ans != -1) return ans;

    ans = fun(v ,ind + 1 , one , two , thr);
    if(thr){
        return ans;
    }
    if(one == 0){
        if(v[ind] == 1LL){
            ans+= fun(v, ind + 1LL, 1LL ,two, thr);
            ans%= mod;
        }
    }
    if(one){
        if(v[ind] == 2LL){
            ans+= fun(v, ind + 1LL, 1LL ,1LL, thr);
            ans%= mod;
        }
    }
    if(one and two){
        if(v[ind] == 3LL){
            ans+= fun(v, ind + 1LL, 1LL ,1LL, 1LL);
            ans%= mod;
        }
    }
    return ans;
}

void solve(){
    int n ;
    cin >> n ;
    vector<int>v(n);
    for(auto &x:v) cin >> x;
    for(int i = 0 ; i < n;i++){
        for(int j=0;j < 2; j++){
            for(int k=0;k < 2; k++){
                for(int l=0;l < 2; l++){
                    dp[i][j][k][l] = -1;
                }
            }   
        }
    }
    cout << fun(v,0 , 0, 0 , 0) << sad;

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