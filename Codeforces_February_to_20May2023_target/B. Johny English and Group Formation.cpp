/*
 **** Bismillahir Rahmanir Rahim ****
 */
 
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
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
bool comp(pair<long long , long long>&a , pair<long long  , long long>&b){
    return (a.first > b.first || a.first == b.first and a.second > b.second);
}
void solve(){
    long long n;
    cin >> n;
    vector<long long>v(n);
    map<long long , long long>mp;
    for(auto &x:v) {
        cin >> x;
        mp[x]++;
    }
    long long mx = 0 , ans = 0;
    for(auto &x:mp){
        mx = max(mx , x.second);
    }
    ans = min(n / 2 , n- mx);
    cout << ans + n - 2 * ans << sad;
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