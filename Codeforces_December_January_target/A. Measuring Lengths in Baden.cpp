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
    long long in  , feet ;
    if(n % 3 == 1){
        in = n / 3 ;
    }
    else if( n % 3 == 2){
        in = n / 3 + 1;
    }
    else{
        in = n / 3;
    }
    feet = in / 12.0;
    long long cal = feet * 12 * 3 + 3 * in ;
    long long cal1;
    if(feet > 1)
    cal1= (feet-1) * 12 * 3 + 3 * in ;
    long long cal2 = (feet+1) * 12 * 3 + 3 * in ;
    long long chk = abs(n - cal) ;
    long long chk1 = abs(n - cal1) ;
    long long chk2 = abs(n - cal2) ;
    long long mn = min({chk  , chk2});
    if(mn == chk){
        cout << feet << " " << in % 12 << sad;
    }
    else if(mn == chk2){
        cout << feet + 1<< " " << in % 12 << sad;
    }
    //2nd method think easy.
    /* long long ans = n / 3;
    if(n % 3 == 2) ans++;
    cout << ans /12 << " " << ans % 12 << sad; */
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