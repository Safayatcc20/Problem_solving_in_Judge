 
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
const long long N = 100;
const long long mod = 1e9 + 7;
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
map<int , int> facotrize(int m,vector<int>&pl){
    map<int , int>ans;
    for(auto &x:pl){
        int cnt = 0;
        int temp = x;
        while(temp<= m){
            cnt+=m/temp;
            temp*=x;
        }
        ans[x] = cnt;
    }
    return ans;
}
map<int , int> facotrizes(int m,vector<int>&pl){
    map<int , int>ans;
    for(auto &x:pl){
        if(x * x > m) break;
        int cnt = 0;
        int temp = x;
        while(m%temp == 0){
            ans[x]++;
            m/=x;
        }
    }
    if(m > 1)
    ans[m]++;
    return ans;
}
int howmanydiv(map<int , int>&ass){
    int ans = 1;
    for(auto &x:ass){
        ans = (ans * (x.second + 1)) % mod;
    }
    return ans;
}
void solve(){
    int n,m;
    cin >> n >> m;
    vector<int>v(n),ans(n);
    for(auto &x:v) cin >> x;
    map<int , int>factorofm= facotrize(m , pl);
    for(int i = 0 ; i < n;i++){
        map<int , int>achi = facotrizes(v[i],pl);
        map<int , int>ass = factorofm;
        for(auto &x:achi){
            ass[x.first] += x.second;
        }
        ans[i] = howmanydiv(ass);
    }
    for(auto &x:ans){
        cout << x << " ";
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
    sieve();
    //cin >> t;
    while (t--)
    {
        solve();
    }
}
/* 
Solution

PROBLEM LINK:
Practice
Contest: Division 1
Contest: Division 2
Contest: Division 3
Contest: Division 4

Author: eiandy_eahnady
Tester: mexomerf
Editorialist: iceknight1093

DIFFICULTY:
TBD

PREREQUISITES:
Prime factorization (using a sieve)

PROBLEM:
Given an array 
A
A of length 
N
N and an integer 
M
M, find for each 
i
i the number of divisors of 
A
i
⋅
M
!
A 
i
​
 ⋅M!.

M
,
A
i
≤
1
0
7
M,A 
i
​
 ≤10 
7
  for this version.

EXPLANATION:
Read the solution to the easy version first.

In this version, since 
M
≤
1
0
7
M≤10 
7
 , there can be many primes in the factorization of 
M
!
M! (there will be 
O
(
M
log
⁡
M
)
O( 
logM
M
​
 ) in fact, due to the prime number theorem).
This means the previous solution of computing the prime factorization of 
A
I
⋅
M
!
A 
I
​
 ⋅M!, then computing the number of divisors from the product of powers will be too slow - we’ll need to iterate over all the primes (and there can be over 
6
⋅
1
0
5
6⋅10 
5
  of them) for each index, which is much too slow.

However, let’s look at this from the opposite perspective: the 
A
i
A 
i
​
  values remain small, and the prime factorizations of 
M
!
M! and 
M
!
⋅
A
i
M!⋅A 
i
​
  differ only in the primes dividing 
A
i
A 
i
​
 .
This means only at most 
8
8 primes change their powers between 
M
!
M! and 
M
!
⋅
A
i
M!⋅A 
i
​
 .

This allows us to do the following:

Compute the prime factorization of 
M
!
M!, and from this factorization the number of its divisors - say 
D
D.
This is done only once, at the start.
Let 
b
i
b 
i
​
  denote the power of 
i
i in this factorization (where 
b
i
=
0
b 
i
​
 =0 if 
i
i isn’t prime, of course).
Then, to compute the number of divisors of 
A
i
⋅
M
!
A 
i
​
 ⋅M!:
Prime factorize 
A
i
A 
i
​
  in 
O
(
log
⁡
A
i
)
O(logA 
i
​
 ) using the sieve.
For each prime 
p
p dividing 
A
i
A 
i
​
 , say with a power of 
k
k, the term in the product should be
(
b
p
+
k
)
(b 
p
​
 +k), while it’s currently just 
b
p
b 
p
​
 .
To quickly simulate this, simply divide 
D
D by 
b
p
b 
p
​
  and then multiply it by 
(
b
p
+
k
)
(b 
p
​
 +k).
The final value of 
D
D is the answer for this 
A
i
A 
i
​
 .
We perform at most 
log
⁡
2
A
i
log 
2
​
 A 
i
​
  divisions this way, and so even doing each of them in 
O
(
log
⁡
M
O
D
)
O(logMOD) time using Fermat’s little theorem is fast enough.
Also, since 
A
i
≤
1
0
7
A 
i
​
 ≤10 
7
 , factorizing each 
A
i
A 
i
​
  in square-root time is likely too slow.
Instead, we can use the fact that 
A
i
≤
1
0
7
A 
i
​
 ≤10 
7
  to quickly prime factorize using a sieve.

Specifically, run a sieve of Eratosthenes to compute, for each number from 
1
1 to 
1
0
7
10 
7
 , one of its prime divisors.
Then, to factorize 
A
i
A 
i
​
 , simply look up the precomputed prime divisor of 
A
i
A 
i
​
  (say 
p
p), and then factorize 
A
i
p
p
A 
i
​
 
​
  instead (which can be done in the same way: divide out one of its prime divisors and so on).

That is, if 
prm
[
x
]
prm[x] denotes the precomputed prime factor of 
x
x, the prime factors of 
A
i
A 
i
​
  are exactly

prm
[
A
i
]
,
prm
[
A
i
prm
[
A
i
]
]
,
…
prm[A 
i
​
 ],prm[ 
prm[A 
i
​
 ]
A 
i
​
 
​
 ],…
Note that 
x
x can have at most 
log
⁡
2
x
log 
2
​
 x prime divisors, so each 
A
i
A 
i
​
  can be factorized in 
O
(
log
⁡
A
i
)
O(logA 
i
​
 ) time.

TIME COMPLEXITY:
O
(
M
log
⁡
log
⁡
M
+
N
log
⁡
(
max
⁡
A
)
log
⁡
M
O
D
)
O(MloglogM+Nlog(maxA)logMOD) per testcase.

CODE:
 Author's code (C++)
code:
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = 1e7 + 5,mod = 1e9 + 7;

#define int long long

int prime[M], n, m;
int b[N], mp[M];
int divs = 1;
vector<int> primes;

int add (int x , int y)
{
      x %= mod;
      y %= mod;
    return (x + y) % mod;
}
int mul (int x , int y)
{
    x %= mod;
    y %= mod;
    return (x * y) % mod;
}
void sieve() {
    for (int i = 2; i < M; i++)
        prime[i] = i;
    for (int i = 2; (i * i) < M; i++) {
        for (int j = (i * i); j < M; j += i) {
            if (prime[i] == i) {
                prime[j] = i;
            }
        }
    }
}


int fastPower(int base, int power)
{
       if(!power)
           return 1;
       int half = fastPower(base,power / 2);
       int ans = mul(half,half);
       if(power & 1) ans = mul(ans,base);
       return ans;
}
int f(int x)
{

    int ans = divs;
    map<int, int> mp2;
    while (x != 1)
    {
        mp2[prime[x]]++;
        x /= prime[x];
    }
    for (auto i: mp2)
    {
        ans = mul(i.second + 1 + mp[i.first],ans) ;
        ans = mul(ans, fastPower(mp[i.first] + 1, mod - 2));
    }
    return ans;
}

signed main()
{
    sieve();
    cin >> n >> m;
    for (int i = 2; i <= m; ++i)
    {
        if (prime[i] == i)
        {
            primes.push_back(i);
        }
    }
    for (int i = 2; i <= m; i++)
    {
        int x = i;
        while (x != 1)
        {
            mp[prime[x]]++;
            x /= prime[x];
        }
    }
    for (auto i: primes)
    {
        divs = mul(divs,mp[i] + 1);
    }
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        b[i] = f(x);
    }
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}
code tester:
#include <bits/stdc++.h>
using namespace std;
#define md 1000000001
#define int long long
#define I long long
#define N 10000001
int dp[N] = {};
vector<int> prm;
int cnt[N] = {};
I modex(I a,I b,I m){
  a=a%m;
  if(b==0){
    return 1;
  }
  I temp=modex(a,b/2,m);
  temp=(temp*temp)%m;
  if(b%2){
    temp=(temp*a)%m;
  }
  return temp;
}
I mod(I a,I b,I m){
  a=a%m;
  b=b%m;
  I c=__gcd(a,b);
  a=a/c;
  b=b/c;
  c=modex(b,m-2,m);
  return (a*c)%m;
}
int32_t main() {
    for(int i = 2; i < N; i++){
        if(dp[i] == 0){
            int x = i;
            prm.push_back(i);
            while(x < N){
                if(dp[x] == 0){
                    dp[x] = i;
                }
                x += i;
            }
        }
    }
	int n, m;
	cin>>n>>m;
	int num = 1;
    for(int i = 0; i < prm.size(); i++){
        int x = prm[i];
        while(1){
            int temp = m / x;
            if(temp == 0){
                break;
            }
            cnt[prm[i]] += temp;
            x *= prm[i];
        }
        num *= (1 + cnt[prm[i]]);
        num %= md;
    }
	int a[n];
	int ans[n];
	for(int i = 0; i < n; i++){
	    cin>>a[i];
	    int x = a[i];
	    ans[i] = num;
	    while(x > 1){
	       int y = dp[x];
	       int temp = 0;
	        while(x % y == 0){
	            temp++;
	            x /= y;
	        }
	        //cout<<cnt[y]<<"\n";
	        ans[i] = mod(ans[i] * (1 + cnt[y] + temp), (1 + cnt[y]), md);
	        //cout<<ans[i]<<"\n";
	    }
	    cout<<ans[i]<<" ";
	}
	cout<<"\n";
}
 */