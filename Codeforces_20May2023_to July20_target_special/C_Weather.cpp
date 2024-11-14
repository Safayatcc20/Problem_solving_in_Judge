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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n ;
    cin >> n;
    vector<int>v(n) ,  p(n), neg(n);
    for(auto &x:v) cin >> x;
    int ans = INT_MAX;
    bool pos = 0 , ne = 0;
    for(int i = 0 , j = n-1; i < n and j >= 0; i++ , j--){
        if(v[i] >= 0){
            if(pos){
                p[i] = p[i-1] + 1;
            }
            else{
                p[i] = 1;
                pos=true;
            }
        }
        else{
            if(pos){
                p[i] = p[i-1] ;
            }
            else{
                p[i] = 0;
                pos=true;
            }
        }
        if(v[j] <= 0){
            if(ne){
                neg[j] = neg[j+1] + 1;
            }
            else{
                neg[j] = 1;
                ne = true;
            }
        }
        else{
            if(ne){
                neg[j] = neg[j+1];
            }
            else{
                neg[j] = 0;
                ne = true;
            }
        }
    }
    for(int i = 0; i < n  - 1; i++){
        ans = min(ans , p[i] + neg[i+1]);
    }
    cout << ans << sad;
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