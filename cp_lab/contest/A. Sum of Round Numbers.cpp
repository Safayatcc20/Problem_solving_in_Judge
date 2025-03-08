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
    int n  ;
    cin  >> n;
    vector<int>v;
    bool a = false , b = false , c = false , d = false , e = false;
    if(n >= 10000){
        a = true;
        v.push_back(n % 10);
        n /=10;
    }
    if(n >= 1000){
        b = true;
        if(a)
        v.push_back((n % 10)*10);
        else
        v.push_back((n % 10)*1);
        n /=10;
    }
    if(n >= 100){
        c = true;
        if(a and b)
        v.push_back((n % 10) * 100);
        else if(b){
        v.push_back((n % 10) * 10);
        }
        else
        v.push_back((n % 10) * 1);
        n /= 10;
    }
    if(n >= 10){
        d = true;
        if(a and b and c)
        v.push_back((n % 10) * 1000);
        else if(b and c)
        v.push_back((n % 10) * 100);
        else if(c)
        v.push_back((n % 10) * 10);
        else
        v.push_back((n % 10) * 1);
        n /=10;
    }
    if(n > 0){
        e = true;
        if(a and b and c and d)
        v.push_back((n % 10) * 10000);
        else if(b and c and d)
        v.push_back((n % 10) * 1000);
        else if(c and d)
        v.push_back((n % 10) * 100);
        else if(d)
        v.push_back((n % 10) * 10);
        else
        v.push_back((n % 10) * 1);
    }
    vector<long long>vv;
    for(auto &x:v){
        if(x) vv.push_back(x);
    }
    cout << vv.size() << sad;;
    for(auto &x:vv) cout << x << " " ;
    cout << sad;
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