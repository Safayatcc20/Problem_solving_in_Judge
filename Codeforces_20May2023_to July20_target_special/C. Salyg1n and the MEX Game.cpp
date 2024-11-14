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
    long long n;
    cin >> n ;
    set<long long>s;
    for(int i = 0 ; i < n ; i++){
        long long x;
        cin >> x;
        s.insert(x);
    }
    set<long long>mex;
    for(int i = 0 ; i <=n+1; i++){
        if(s.find(i) == s.end()) mex.insert(i);
    }
    long long operation = 0 ;
    while(operation <= 2 * n){
        cout << *mex.begin() << sad;
        mex.erase(mex.begin());
        long long y;
        cin >> y;
        if( y == -1) return;
        s.erase(y);
        mex.insert(y);
        operation++;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.flush();
    // long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}