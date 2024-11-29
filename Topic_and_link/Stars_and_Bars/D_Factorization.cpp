 
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

const long long N = 1e7 + 10;
bool prime[N+1];
vector<long long>pl;
void sieve()
{
    prime[1] = prime[0] = true;
    //jodi isprime use na kori tkn ei line use korte hobe
    //for (long long i = 3; i * i <= N; i += 2) prime[i] = true;
    for (long long i = 3; i * i <= N; i += 2)
    {
        if (prime[i])
        {
            continue;
        }
        for (long long j = i * i; j < N; j += i + i)
        {
            prime[j] = true;
        }
    }
    for (long long i = 2; i<= N; i++)
       if(prime[i] == false) pl.push_back(i);
}
bool isprime(long long x)
{
    if (x == 2)
        return true;
    else if ((x % 2 == 0))
        return false;
    return !prime[x];
}
vector<int>primelist;
bool is_composite[N];
//Linear Sieve
//the code below performs in O(n) complexity for seive
void linear_sieve () {
    std::fill (is_composite, is_composite + N, false);
    for (int i = 2; i < N; ++i) {
      if (!is_composite[i]) primelist.push_back (i);
      for (int j = 0; j < primelist.size () && i * primelist[j] < N; ++j) {
           is_composite[i * primelist[j]] = true;
           if (i % primelist[j] == 0) break;
      }
    }
}
//recurrence nCk = (n-1)C(k) + (n-1)C(k-1)
//symmetry rule nCk = nC(n-k) or aCb = aC(a-b)
//nCr = summation of (0 to r) range ∑(n-1+j)C(j) here 0<=j <=r
//sum over k ∑(nCk) = 2^n where 0<=k <= n
// sum over n ∑(mCk)= (n+1)C(k+1) where k is fixed and 0<=m <= n
// sum over n and k  ∑(n+k)C(k)= (n+m+1)C(m) where 0<= k<= m
// sum of squars (nC0)^2 + (nC1)^2+...+(nCn)^2 = (2*n)C(n);
// weighted sum 0*(nC0)+ 1*(nC1)+2*(nC2)...+n(nCn)^2 = (2^(n-1))*(n);
// Fibonacci number (nC0) + (n-1)C1 + ...+(n-k)Ck+...+0Cn = F(n+1);

//Keep mind to call prec in main 
//carefull for constraint N
const int NN = 2e6 + 9, mod = 1e9 + 7;
// Using Extended Euclidean Algorithm 
int f[NN], inv[NN], finv[NN];
void prec() {
  f[0] = 1;
  for (int i = 1; i < NN; i++) f[i] = 1LL * i * f[i - 1] % mod;
  inv[1] = 1;
  for (int i = 2; i < NN; i++ ) {
    inv[i] = (-(1LL * mod / i) * inv[mod % i] ) % mod;
    inv[i] = (inv[i] + mod) % mod;
  }
  finv[0] = 1;
  for (int i = 1; i < NN; i++) finv[i] = 1LL * inv[i] * finv[i - 1] % mod;
}
int nCr(int n, int r) {
  if (n < r || n < 0 || r < 0) return 0;
  return 1LL * f[n] * finv[n - r] % mod * finv[r] % mod;
}
void solve(){
    int n , m;
    cin >> n >> m;
    //m = p1^e1 * p2^e2....
    //so e1, e2, e3,... ek will distribute in N position 
    // for each prime calculate = C(e+ n -1 , n-1)
    map<int,int>mp;
    for(auto &x:pl){
        if(x * x > m) break;
        int cnt = 0;
        while(m % x ==0){
            cnt++;
            m/=x;
        }
        mp[x]= cnt;
    }
    if(m >1) mp[m]++;
    int ans = 1;
    for(auto &x:mp){
        ans*= nCr(x.second + n -1 , n-1)%mod;
        ans %= mod;
    }
    cout << ans << sad;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    prec();
    sieve();
    //cin >> t;
    while (t--)
    {
        solve();
    }
}