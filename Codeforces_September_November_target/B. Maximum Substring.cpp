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
void solve(){
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long one = 0 , zero = 0;
    for(long long i = 0 ; i < n ; i++){
        if(s[i] == '1'){
            one++;
        }
        else{
            zero++;
        }
    }
    long long out = 0 , get = 0 , take = one * zero;
    one = zero = 0;
    for(long long i = 0;  i < n ; i++){
        if(s[i] == '1'){
            one++;
            get = max(zero*zero , get);
            zero = 0;
        }
        else{
            out = max(out , one * one );
            one = 0;
            zero++;
        }
    }
    get = max(zero*zero , get);
    out = max(out , one * one );
    cout << max({get , out , take}) << sad;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}