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
void solve(){
    long long n ,  q;
    cin >> n >> q;
    vector<long long>v(n), pre(n+1);
    for(auto &x:v) cin >> x;
    pre[0] = 0;
    pre[1] = 0;
    long long store = 0;
    for(long long i = 2; i <  n ; i++){
        if(v[i-2] >= v[i-1] and v[i-1]>= v[i])store++;
        pre[i] = store;
    }
    /* for(auto &x:pre){
        cout << x << " " ;
    } */
    while(q--){
        long long l , r;
        cin >> l >> r;
        l--; r--;
        if(l == r){
            cout << 1 << sad;
            continue;
        }
        long long ans = r-l+1;
        ans -= (pre[r] - pre[l+1]);
        cout << ans << sad;
    }
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