 
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
const long long N = 1e5 + 10;
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
    primelist.push_back (1);
    for (int i = 2; i < N; ++i) {
      if (!is_composite[i]) 
      primelist.push_back (i);
      for (int j = 0; j < primelist.size () && i * primelist[j] < N; ++j) {
           is_composite[i * primelist[j]] = true;
           if (i % primelist[j] == 0) break;
      }
    }
}
int NN = 1e5+10;
vector<vector<int>>divisor(NN , vector<int>());
void divisors(){
    for(int i = 1; i< NN ;i++){
        for(int j = i; j < NN; j+=i){
            divisor[j].push_back(i);
        }
    }
}
void solve(){
    int n , m;
    cin >> n>> m;
    vector<int>v(m);
    for(int i = 0; i< m; i++) cin >> v[i];
    if(m == 1 and n > 1) {
        cout << -1 << sad;
        return;
    }
    vector<int>index(n+1);
    reverse(all(v));
    for(int i = 0; i< m; i++) index[v[i]] = i;
    vector<int>ans(n+1);
    ans[1] = v[0];
    // if(m > 1) ans[2] = v[1];
    // if(n> 2 and m > 1) ans[3] = v[1];
    for(int i = 2; i<= n ; i++){
        int cnt = 0, kothaihobe = 0;
        for(auto &x:divisor[i]){
            if(i != x){
                kothaihobe = max(kothaihobe , index[ans[x]]);
            }
        }
        //cout << i << " "<< cnt << " "<< kothaihobe << sad;
        
        if(kothaihobe+1 >= m){
            cout << -1 << sad;
            return;
        }
        ans[i] = v[kothaihobe+1];
    }
    for(int i = 1; i<= n;i++){
        cout <<ans[i] << " " ; 
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
    cin >> t;
    divisors();
    while (t--)
    {
        solve();
    }
}