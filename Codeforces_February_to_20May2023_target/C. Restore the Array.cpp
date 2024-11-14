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
    long long n;
    cin >> n ;
    vector<long long>a, b(n-1);
    set<long long>s;
    for(auto &x:b) {cin >> x; s.insert(x);}
    if(s.size() == 1){
        for(long long i = 0 ; i < n ;i++){
            cout << b[0] << " ";
        }
        cout << sad;
        return;
    }
    if(b[0] == b[1]){
        a.push_back(b[0]);
        a.push_back(b[1]);
    }
    else{
        a.push_back(b[0]);
        a.push_back(min(b[0] , b[1]));
    }
    for(long long i = 2 ; i < n - 1;i++){
        if(b[i] < b[i-1]){
            a.push_back(b[i]);
        }
        else{
            a.push_back(b[i-1]);
        }
    }
    a.push_back(b[n-2]);
    for(auto &x:a) cout << x << " " ;
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