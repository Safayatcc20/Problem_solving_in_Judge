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
    double px , py;
    cin >> px >> py;
    double ax , ay;
    cin >> ax >> ay;
    double bx , by ;
    cin >> bx >> by;
    double f1 = sqrtf((px-ax)*((px-ax)) + (py-ay) * (py-ay));
    double f2 = sqrtf((px-bx)*((px-bx)) + (py-by) * (py-by));
    double f3 = (sqrtf((ax-bx)*((ax-bx)) + (ay-by) * (ay-by)))/2.0;
    double f4 = (sqrtf((ax-0)*((ax-0)) + (ay-0) * (ay-0)));
    double f5 = (sqrtf((bx-0)*((bx-0)) + (by-0) * (by-0)));
    double ans = INT_MAX;
    ans = min( ans , max({f3 , f1 , f5}));
    ans = min( ans , max({f2 , f3 , f4}));
    cout << fixed << setprecision(10) << min(min(ans , max(f1 , f4)) , max(f2 , f5)) << sad;
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