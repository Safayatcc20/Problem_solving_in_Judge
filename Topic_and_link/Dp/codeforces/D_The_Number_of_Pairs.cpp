 
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
#define MAXN 20000000+100 // Carefull when solving the problem
 
// stores smallest prime factor for every number
int spf[MAXN] = {0};
 
// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
    spf[1] = 0;
 
    // separately marking spf for every even
    // number as 2
    for (int i = 2; i < MAXN; i += 2)
        spf[i]++;
 
    for (int i = 3; i < MAXN; i++) {
        // checking if i is prime
        if (spf[i] == 0) {
            // marking SPF for all numbers divisible by i
            for (int j = i ; j < MAXN; j += i)
 
                // marking spf[j] if it is not
                // previously marked
                    spf[j]++;//how many divisor except 1 and itself
        }
    }
}
 
// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
 //key shortcut ctrl + d u can select same name for this 
// remember mod depends on statement;
const long long mod = 1e18; // 10^9

int bin_power(int a, int n ,int mod) {
  int ans = 1% mod;
  while(n){
    if(n & 1) ans = 1LL * ans * a % mod;
    a = 1LL * a * a % mod;
    n >>= 1;
  }
  return ans;
}
void solve(){
    // https://www.geeksforgeeks.org/given-gcd-g-lcm-l-find-number-possible-pairs-b/
    int c , d , x;
    cin >> c >> d >> x;
    /* 
        c*lcm(a , b) - d * gcd( a, b) = x
        c * (A*g*B*g / g) - d * g = x; 
        here a * b = A * g * B*g = gcd( a, b ) = g
        also gcd(A , B) = 1 due to A , B are coprime;
        A * B = (x / g + d ) / c; 
    */
   /* // lcm(a,b) * c - gcd(a, b) * d = x; ...... (1)
    // gcd(a, b) = g;
    // a = A*g   b = B * g .... gcd(A, B) = 1;
 
    // putting it to eq(1):
 
    // c * a * b / g - g * d = x;
    // c * A*g * B * g / g - g * d = x;
    // c * A * g * B - g * d = x;
    // g ( c* A*B - d) = x;
    // c* A*B - d = x / g;
 
    // let p = x / g; // p is all the divisors of x because x / g must be an integer
 
    // A*B = (p+d)/c = M;
 
    // conclusion: for all M find the no. of pairs (A, B) such that A and B are coprime and they are integer
 
    // finding no. of pairs :
    // gcd(A, B) = 1;
    // A*B = M
 
 
    // M = p1^c1 * p2^c2 ....... * pN^cN
 
    // because A and B are coprime they cannot have any common prime.
    // so we are distributing the primes of M between A and B such that A and B are coprime
 
 
    // cnt = no. of distinct primes in ppf of M
 
    // no. of ways to distribute primes = ncr(cnt, 0) + ncr(cnt, 1) + ..... + ncr(cnt, cnt) = 2 ^ cnt;
 
    // no. of pairs = 2 ^ cnt
    // ans += no. of pairs; */
    int ans = 0 ;
    for(int i = 1; i* i <= x; i++){
        if( x % i ) continue;
        if((x/ i + d) % c == 0) ans+= 1ll<<(spf[(x  / i + d ) /c]);//bin_power(2 , spf[(x/ i + d) / c] , 1e18);
        if(i * i == x) continue;
        if(( i + d) % c == 0) ans += 1ll<<(spf[( i + d ) /c]);//bin_power(2 , spf[(i + d) / c] , 1e18);
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
    sieve();
    cin >> t;
    while (t--)
    {
        solve();
    }
}