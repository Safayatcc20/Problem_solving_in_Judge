 
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
 //key shortcut ctrl + d u can select same name for this 
// remember mod depends on statement;
const long long mod = 1000000007; // 10^9

int bin_power(int a, int n ,int mod) {
  int ans = 1% mod;
  while(n){
    if(n & 1) ans = 1LL * ans * a % mod;
    a = 1LL * a * a % mod;
    n >>= 1;
  }
  return ans;
}
int inverse(int a, int p) {
  return bin_power(a, p - 2, p);
}

const long long MOD = 1000000007;
const int MAXN = 1000005;
const int MAXK = 101;

vector<long long> fact(MAXN , 1);        // Factorial array
vector<long long> inv_fact(MAXN , 1);    // Inverse factorial array


// Precompute factorials and their inverses modulo MOD
void precompute_factorials() {
    for (int i = 2; i <= MAXN ; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    inv_fact[MAXN ] = inverse(fact[MAXN ], MOD);  // Fermat's little theorem
    for (int i = MAXN - 2; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}

// Compute C(n, k) % MOD using factorials and inverse factorials
long long binomial(long long n, long long k) {
    if (k < 0 || k > n) return 0;
    return (fact[n] * inv_fact[k] % MOD) * inv_fact[n - k] % MOD;
}

void solve(){
    int n  , q;
    cin >> n >> q;
    vector<int>v(n);
    for(auto &x:v) cin >> x;
    precompute_factorials();
    vector<vector<int>>start(n+1 , vector<int>(101,0));
    vector<vector<pair<int , int>>>last(n+1);
    for(int i = 0 ;i <q;i++){
        int l , r , k;
        cin >> l >> r >> k;
        start[l-1][k]++;
        last[r].push_back({k , l-1});
    }
    vector<int>contribution(101, 0);
    for(int i = 0 ;i <n; i++){
        vector<int>range = start[i];
        int sum = 0 ;
        for(int j = 100; j>= 0 ;j--){
            sum = (sum + contribution[j]) % mod;
            range[j]  = (sum + range[j]) % mod;
        }
        contribution = range;
        for(auto &x:last[i]){
            for (int j = 0; j <= x.first; j++) {
                contribution[j] = (contribution[j] - binomial(i - x.second - 1 + x.first - j, x.first - j) + mod) % mod;
            }
        }
        for (int j = 100; j >= 0; j--) {
            v[i] = (v[i] + contribution[j]) % mod;
        }
        
        if (v[i] < 0) v[i] += mod;
        cout << v[i] << " ";
    }
    cout << sad;
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