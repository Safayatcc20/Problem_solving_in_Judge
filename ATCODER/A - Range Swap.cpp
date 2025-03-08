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
    long long n ,  p , q , r , s;
    cin >> n >> p >> q  >> r >> s;
    vector<long long>v(n+1), c(abs(p-q+1)), d(abs(r-s+1));
    for(long long i = 1 ; i<= n ; i++){
        cin >> v[i];
    }
    /* for(long long i =  p ; i <= q; i++){
        c.push_back(v[i]);
    }
    for(long long i =  r ; i <= s; i++){
        d.push_back(v[i]);
    }
    for(long long i =  p ; i <= q; i++){
        v[i] = d[i];
    }
    for(long long i =  r ; i <= s; i++){
        v[i] = c[i];
    } */
    for(long long i = p , j = r ; i <= q && j <= s; i++ , j++){
        swap(v[i] , v[j]);
    }
    for(long long i = 1; i <= n ; i++){
        cout << v[i] << " ";
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