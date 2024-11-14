/*
 **** Bismillahir Rahmanir Rahim ****
 */
 
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.rbegin(), b.rend()
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
void solve(){
    int n , k;
    cin >> n >> k;
    vector<int>v(n);
    map<int , int>mp;
    for(auto &x:v) {cin >> x; mp[x]++;}
    vector<pair<int , int>>vv;
    for(auto &x:mp){
        vv.push_back({x.second , x.first});
    }
    int ans = 0 , portion = 0 , chk = 0 , odd = 0;
    sort(all(vv));
    n++;
    for(int i = 0 ; i < vv.size() ;  i++){
       if(portion <= n / 2){
        chk = vv[i].first / 2;
        portion += (vv[i].first / 2);
        ans += min(chk * 2 , vv[i].first);
        if(vv[i].first & 1) odd++;
       } 
    }
    if(portion <= n  / 2){
        if(odd){
            int r = (n / 2 - portion);
            portion += min(odd , r);
        //cout << portion << sad;
            ans += min(odd , r);
        }
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
    //cin >> t;
    while (t--)
    {
        solve();
    }
}