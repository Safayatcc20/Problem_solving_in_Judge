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
    long long n , m  , k;
    cin >> n >> m >> k;
    vector<long long>j(n) , g(m);
    long long je = 0 , gg = 0 ;
    for(auto &x:j) {cin >> x; je += x;}
    for(auto &x:g) {cin >> x; gg += x;}
    sort(all(g));
    sort(all(j));
    if(k == 1){
        if(j[0] >= g[m-1]) cout << je << sad;
        else cout << je - j[0] + g[m-1] << sad;
        return ; 
    }
    if(j[0] >= g[m-1]){
        if(!(k&1)) {
            cout << je - j[n] + g[0] << sad;
        }
        else cout << je << sad;
        return;
    }
    else if(j[n-1] <= g[0]){
        if(k&1) {
            cout << je + g[m-1]  - j[0] << sad;
        }
        else cout << je << sad;
        return;
    }
    else{
        je += g[m-1] - j[0];
        swap(g[m-1] , j[0]);
        sort(all(j));
        sort(all(g));
        if((k-1) & 1) {
            je += g[0] - j[n-1];
        }
        cout << je << sad;
    }
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