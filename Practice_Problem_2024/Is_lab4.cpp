 
 /***** Bismillahir Rahmanir Rahim *****/
 
#include <bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T> using oset = tree<T , null_type , less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
 //key shortcut ctrl + d u can select same name for this 
// remember mod depends on statement;
const long long mod = 99244353; // 10^9

// a ^ n % mod
int power(int a, int n, int mod) {
  if (n == 0) return 1LL;
  if (n == 1) return a % mod;
  if (n % 2 == 0) {
    int x = power(a, n / 2, mod);
    return 1LL * x * x % mod;
  }
  else {
    int x = power(a, n / 2, mod);
    return (1LL * x * x) % mod * a % mod;
  }
}
int iterative_power(int a, int n) {
  int ans = 1;
  while (n) {
    if (n % 2 == 1) ans = 1LL * ans * a % mod;
    a = 1LL * a * a % mod;
    n /= 2;
  }
  return ans;
}
int bin_power(int a, int n ,int mod) {
  int ans = 1% mod;
  while(n){
    if(n & 1) ans = 1LL * ans * a % mod;
    a = 1LL * a * a % mod;
    n >>= 1;
  }
  return ans;
}

// 1 / a % p
int inverse(int a, int p) {
  return power(a, p - 2, p);
}

// a * n % mod;
// if the value is less than equal to 2^63 then use unsigned long long
// if greater __int128
// otherwise used long long
unsigned long long mulmod(unsigned long long a, unsigned long long n, __int128 mod) {
  unsigned long long ans = 0 ;
  while(n){
    // if the value is less than equal to 2^63 then remove the int128;
    if(n & 1) ans = ((__int128) ans + a ) % mod;
    a = ((__int128) a + a) % mod;
    n >>= 1;
  }
  return ans;
}
// a * n % mod;
long long mulmod_easy(long long a, long long n, long long mod) {
  return __int128(a) * n % mod;
}
void solve(){


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