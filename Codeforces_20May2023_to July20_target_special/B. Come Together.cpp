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
    long long a , aa , b ,bb ,c ,cc;
    cin >> a >> aa >> b >> bb >> c >> cc;
    if(a == b and a == c and aa == bb and bb == cc){
        cout << 1<< sad;
        return;
    }
    if(a == b and a == c and ((aa >= bb and aa <= cc) || (aa <= bb and aa >= cc))){
        cout << 1 << sad;
        return;
    }
    if(aa == bb and bb == cc and ((a <= b and a >= c) || (a >= b and a <= c))){
        cout << 1<< sad;
        return;
    }
    //y calculation
    long long ymin = min(abs(aa - bb) , abs(aa - cc));
    // x 
    long long xmin = min(abs(a - b) , abs(a - c));
    long long ans = 1;
    long long xa = min({a , b , c});
    long long xaa = max({a , b , c});
    if(((a < b and a < c) or (a > b and a > c))){
        ans += xmin;
    }
    if(((aa < bb and aa < cc) or (aa > bb and aa > cc))){
        ans += ymin;
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