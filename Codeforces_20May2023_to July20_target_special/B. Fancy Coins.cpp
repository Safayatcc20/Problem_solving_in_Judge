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
    long long m , k , a1 , ak;
    cin >> m >> k >> a1 >> ak;
    if( a1 >= m){
        cout << 0 << sad;
    }
    else if(m / k <= ak and m % k <= a1){
        cout << 0 << sad;
    }
    else{
        long long ft = min(m / k  , ak);
        long long sec = min(m - k * ft , a1);
        long long baki = m - ft * k - sec;
        //cout << ft << " " << sec  << " " << baki << sad;
        if( baki % k == 0){
            cout << baki / k << sad;
        }
        else if((k - baki % k) <= sec) cout << baki / k + 1 << sad;
        else cout << baki / k + baki % k << sad; 
    }
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