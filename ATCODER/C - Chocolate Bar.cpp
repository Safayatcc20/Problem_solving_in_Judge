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
    long long h , w;
    cin >> h >> w;
    if(h % 3 == 0 || w % 3== 0){
        cout << 0 << sad;
        return;
    }
    long long ans = w;
    for(long long i = 1; i < h ; i++){
        long long   a = i *w;
        long long   b = (h-i) *(w/2);
        long long   c = (h-i) *(w-w/2);
        ans = min(ans , max({a , b , c}) - min({a , b , c}));
    }
    long long sum = h;
    for(long long i = 1; i < w ; i++){
        long long   a = i * h;
        long long   b = (w-i) *(h/2);
        long long   c = (w-i) *(h-h/2);
        sum = min(sum , max({a , b , c}) - min({a , b , c}));
    }
    cout << min(ans , sum) << sad;
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