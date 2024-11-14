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
    long long n , k;
    cin >> n >> k;
    if((k % 10) != 1 and (k % 10) & 1){
        na;
        return;
    }
    bool f = false;
    vector<long long>v;
    v.push_back(n);
    while(n <= k){
        if(n *10+1 == k || (n *10+1)*2 == k){
            n = n * 10 + 1;
            v.push_back(n);
        }
        else{
            n *= 2;
            v.push_back(n);
        }
        if(n == k){
            f = true;
            break;
        }
    }
    if(f){
        ha;
        cout << v.size() << sad;
        for(auto x:v ){
            cout << x << " ";
        }
        cout << sad;
    }
    else{
        na;
        for(auto x:v ){
            cout << x << " ";
        }
        cout << sad;
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