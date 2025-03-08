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
    int h , m;
    cin >> h >> m;
    int l = h % 10 , r = (m / 10)% 10;
    int take = h , out = m;
    take /=10;
    take = take * 10 + r;
    out = out % 10;
    out = l * 10 + out;
    if(h > 15 and h < 20){
        cout << 20 << " " << 0 << sad;
        return;
    }
    //cout << take << " " << out << sad;
    if(take < 24 and out < 60){
        cout << h << " " ;
        cout << m << sad;
    }
    else{
        if(h == 23 ){
            if(m <= 39)
            cout << h << " " << m << sad;
            else
            cout << 0 << " " << 0  << sad;
            return;                        
        }
        cout << h+1 << " " << 0 << sad;
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