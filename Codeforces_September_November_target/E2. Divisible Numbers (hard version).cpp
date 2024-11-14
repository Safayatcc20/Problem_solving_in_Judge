/*
 **** Bismillahir Rahmanir Rahim ****
 */
 
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
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
const long long N = 100000000;
long long prime[N] , cnt[N];
long long fact(long long n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}
void solve(){
    long long a , b , c , d;
    cin >> a >> b >> c >> d;
    vector<int>v , vv;
    for(int i = 1; i * i<= a; i++){
        if(a % i == 0){
            v.push_back(i);
            v.push_back(a / i );
        }
    }
    for(int i = 1; i * i<= b; i++){
        if(b % i == 0){
            vv.push_back(i);
            vv.push_back(b / i );
        }
    }
    vector<long long >vvv;
    for(int i = 0 ; i < v.size() ; i++){
        for(int j = 0 ;j < vv.size() ;j++){
            vvv.push_back(1ll * v[i] * vv[j]);
        }
    }
    long long x = - 1  , y = - 1;
    for(long long i = 0 ; i < vvv.size() ; i++){
        long long chk = 1ll * a  * b /vvv[i];
        //assert((1ll * a * b )  % vvv[i] == 0);
        if(a < c - c % vvv[i] && b < d - d % chk){
            x = c - c % vvv[i];
            y = d - d % chk;
        }
        if(a < c - c % chk && b < d - d % vvv[i]){
            x = c - c % chk;
            y = d - d % vvv[i];
        }
    }
    cout << x << " " << y << sad;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}