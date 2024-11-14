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
long long t = 1;
const long long mod = 1e9+7;
long long bin_power(long long a, long long n ) {
  long long ans = 1% mod;
  while(n){
    if(n & 1) ans = 1LL * ans * a % mod;
    a = 1LL * a * a % mod;
    n >>= 1;
  }
  return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //long long t;
    
    long long n ;
    cin >> n;
    vector<long long> fact(1000006);
    fact[0] = 1;
    for(long long i = 1; i <1000000+6; i++){
        fact[i] = (fact[i-1] * i ) % mod;
    }
    long long ans = (fact[n] - bin_power(2 , n-1) + mod) % mod;
    cout << ans  << sad;
}