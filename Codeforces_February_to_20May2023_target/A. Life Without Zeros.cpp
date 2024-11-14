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
    long long a , b ;
    cin >> a >> b;
    long long c = a + b;
    long long aa = a , bb = b , cc = c;
    vector<long long>v;
    while(a > 0){
        if(a% 10){
            v.push_back(a%10);
        }
        a /= 10;
    }
    aa = 0;
    reverse(all(v));
    for(long long i = 0 ; i < v.size() ; i++){
        aa = aa * 10 + v[i];
    }
    v.clear();
    while(b > 0){
        if(b% 10){
            v.push_back(b % 10);
        }
        b /= 10;
    }
    bb = 0;
    reverse(all(v));
    for(long long i = 0 ; i < v.size() ; i++){
        bb = bb * 10 + v[i];
    }
    v.clear();
    long long test = c;
    while(c > 0){
        if(c% 10){
            v.push_back(c%10);
        }
        c /= 10;
    }
    cc = 0;
    reverse(all(v));
    for(long long i = 0 ; i < v.size() ; i++){
        cc = cc * 10 + v[i];
    }
    v.clear();
    if(cc == (aa+bb)){
        ha;
    }
    else na;
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