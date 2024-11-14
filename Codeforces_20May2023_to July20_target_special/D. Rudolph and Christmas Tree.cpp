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
    long long n  , d , h;
    cin >> n >> d >> h;
    vector<long long>v(n), store;
    for(auto &x:v) cin >> x;
    sort(all(v));
    long long chk = 0 ;
    for(int i = 0; i < n ; i++){
        if(chk > v[i]){
            store.push_back(chk- v[i]);
        }
        chk = h + v[i];
    }
    double ans = llround(d * h * n);
    ans /= 2;
    double  cnt = 0 ;
    for(int  i = 0 ; i < store.size() ;i++){
        cnt += ((store[i] * store[i]) * d );
    }
    cnt /= (2 * h);
    ans -= cnt;
    cout << fixed << setprecision(6) << ans << sad;
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