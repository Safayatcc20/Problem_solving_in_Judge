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
    long long  n ;
    cin >> n ;
    vector<long long>a(n) , b(n);
    for(auto &x:a) cin >> x;
    for(auto &x:b) cin >> x;
    set<int>s;
    for(int i = 0 ; i < n ; i++){
        if(a[i] == b[i] and a[i] == 0) continue;
        else if(a[i] == 0 ){
            s.insert(0);
            continue;
        }
        long long x = a[i] / gcd(a[i] , b[i]);
        long long y = b[i] / gcd(a[i] , b[i]);
        if( x & 1 and y & 1) s.insert(2);
        else if( y & 1) s.insert(0);
        else s.insert(1);
    }
    if(s.size() > 1) na;
    else ha;
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