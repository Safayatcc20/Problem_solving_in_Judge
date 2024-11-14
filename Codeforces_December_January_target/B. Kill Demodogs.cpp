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
    long long n; cin >> n;
    long long sum = 0, mod = 1000000007;
    sum = (n * (n+ 1)) % mod;
    sum = (sum * (4 * n - 1)) % mod;
    sum /= 6;
    sum = (sum * 2022) % mod;
    cout << sum<<sad;
    /* sum = ((((n %mod)*((n+1)% mod)%mod)*((2*n+1)% mod))%mod)/6;
    //cout << sum << sad;
    long long ans = 0;
    sum = ((sum % mod) + (((((n %mod)*((n+1)% mod)%mod)*((2*n-2)% mod))%mod)/6)% mod)% mod;
    //cout << ans << sad;
    cout << ((2022 % mod)*(sum %mod)%mod) % mod<< sad; */

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