 
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
#define MAXN 10000005 // Carefull when solving the problem
const int mod = 998244353;
// stores smallest prime factor for every number
int spf[MAXN];
 
// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
 
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
 
    // separately marking spf for every even
    // number as 2
    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;
 
    for (int i = 3; i * i < MAXN; i++) {
        // checking if i is prime
        if (spf[i] == i) {
            // marking SPF for all numbers divisible by i
            for (int j = i * i; j < MAXN; j += i)
 
                // marking spf[j] if it is not
                // previously marked
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}
 
// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1) {
        if(ret.empty() or ret.back() != spf[x])
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
void solve(){
    int n;
    cin >> n;
    vector<int>v(n);
    for(auto &x:v) cin >> x;
    vector<int>dp(n , 0) ;
    dp[0] = 1;
    vector<int>cnt(MAXN+1 , 0);
    for(int i = 0 ; i <n; i++){
        vector<int>factor = getFactorization(v[i]);
        for (int mask = 1; mask < (1 << factor.size()); mask++) {
            int d = 1, bit = 0;
            for (int j = 0; j < factor.size(); j++) {
                if (mask & (1 << j)) {
                    bit++;
                    d *= factor[j];
                }
            }
            if (bit & 1) {
                dp[i] = (dp[i] + cnt[d]) % mod;
            } else {
                dp[i] = (dp[i] - cnt[d] + mod) % mod;
            }
        }
        for (int mask = 1; mask < (1 << factor.size()); mask++) {
            int d = 1;
            for (int j = 0; j < factor.size(); j++) {
                if (mask & (1 << j)) {
                    d *= factor[j];
                }
            }
            cnt[d] = (cnt[d] + dp[i]) % mod;
        }

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
    sieve();
    while (t--)
    {
        solve();
    }
}
/* Denote dp[i]=
 the number of ways to get to city i
. Brute-forcing all possible previous cities is out of the question, as this solution will take O(n2⋅log(maxai))
 time complexity. What else can we do?

Instead, consider caseworking on what the greatest common factor can be. Let's keep track of an array count
 which for index i
 keeps track of the sum of dp
 values of all previous cities who has a factor of i
. Say the current city has attractiveness ai
. We can almost recover dp[i]
 by adding up the count
 values of all factors of ai
. Unfortunately, this fails as it overcounts many instances. For example, if gcd(ai,aj)=12
 the dp
 state from i
 will be counted five times: 2,3,4,6,12
.

Note that we don't actually care what the greatest common factor is, since the only requirement is that the greatest common factor is not 1
. This also means that repeat appearances of the same prime number in the factorization of ai
 doesn't matter at all — we can assume each prime factor occurs exactly once. Now, if gcd(ai,aj)=12
, it is only counted three times: 2,3,6
. Now, instead of blindly adding the count
 values from all previous states, let's instead apply the Principle of Inclusion-Exclusion on the prime factors. Let's first add the count
 values from all prime factors, then subtract the count
 values from all factors with two prime factors, then add the count
 values from all factors with three prime factors, and so on. It can be seen that actually, the value is only counted one time now.

So what's the time complexity of this solution? Precomputing the set of all prime number takes O(max(ai)log(max(ai)))
 time (by the harmonic series n1+n2+…+nn≈nlog(n)
). For each number ai
, we have to consider all 2f(ai)
 subsets of prime factors, where f(ai)
 is the number of prime factors of ai
. The number with the most distinct prime factors is 510510=2⋅3⋅5⋅7⋅11⋅13⋅17
, so worst case 2^7=128
 operations are needed per number. This goes to a total operation count of approximately 128⋅n
 which will pass in the time limit.

Note that we may also use the Mobius function to compute the answer. The Mobius function's properties makes it utilize the Principle of Inclusion-Exclusion efficiently. The time complexity of this solution is O(max(ai)log(max(ai))+nmax(d(ai)))
 where d(ai)
 is the maximum number of factors of ai
. This time complexity can be shown to be the same as the above time complexity. */