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
const long long mod = 1e9+7;
long long fact(long long n)
{
    if (n == 0)
        return 1;
    return ((n  % mod)* (fact(n - 1) % mod)) % mod;
}
long long findXor(long long n){//reming: function calling findXor(sending value - 1);
    long long rest = n % 4;
    if(rest == 0) return n;
    if(rest == 1) return 1;
    if(rest == 2) return n+1;
    if(rest == 3) return 0;
}
void solve(){
    long long n;
    cin >> n;
    vector<long long>v(n) , vv(n);
    long long mn = INT_MAX , mi = INT_MAX;
    map<long long , long long>mp  , mv;
    for(auto &x:v) {cin >> x; mp[x]++; mn = min(x , mn); }
    for(auto &x:vv) {cin >> x; mv[x]++; mi = min(mi , x);}
    long long ans = 1;
    sort(all(v));
    sort(all(vv));
    for(long long i = 0 ; i < n ; i++){
        if(v[i] <= vv[i]){
            cout << 0 << sad;
            return;
        }
    }
    if(n == 1){
        if(v[0]  > vv[0]){
            cout << 1 << sad;
            return;
        }
        else{
            cout << 0 <<sad;
            return;
        }
    }
    long long cnt = 0;
    for(long long i = 0; i < n ; i++){
        while(cnt < n   and vv[cnt] < v[i]){
            cnt++;
        }
        ans = (ans * (cnt - i )) % mod;
    }
    cout << ans << sad;
}
int main()
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