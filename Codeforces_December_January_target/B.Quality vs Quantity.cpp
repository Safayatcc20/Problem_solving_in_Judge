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
    long long n;
    cin >> n;
    vector<long long>v(n);
    for(auto &x:v) cin >> x;
    sort(all(v));
    vector<long long>pre(n), suf(n);
    suf[0] = v[n-1];
    pre[0] = v[0];
    for(long long i = 1 ; i < n ; i++){
        pre[i] = v[i] + pre[i-1];
    }
    long long j = 1;
    for(long long i = n- 2; i >= 0; i--){
        suf[j] = v[i] + suf[j-1];
        j++;
    }
    /* for(long long i = 0 ; i < n ;i++){
        cout << pre[i] << "   " << suf[i] << sad;
    } */
    for(long long i = 0 ; i < n ; i++){
        if(i+1 < n ){
            if(pre[i+1] < suf[i]){
                ha;
                return;
            }
        }
    }
    na;
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