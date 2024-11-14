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
    int n , m;
    cin >> n >> m;
    map<pair<int, int>, int>mp;
    for(int i = 1 ; i <= m ; i++){
        int x , y;
        cin >> x >> y;
        mp[{x, y}] = i;
    }
    /* for(auto &x:mp){
        cout << x.first.first << " " << x.first.second<< " " << x.second << sad;
    } */
    int ans = INT_MAX;
    for(int j = 1; j < n - 1; j++){
        for(int k = 1; k < n - 1; k++){
            if(mp[{j , k}] == 0 or mp[{j , k+1}] == 0 or mp[{j , k+2}] == 0 or mp[{j + 1, k}] == 0 or mp[{j + 1, k+1}] == 0 or mp[{j + 1, k+2}] == 0 or mp[{j + 2, k}] == 0 or mp[{j + 2, k+1}] == 0 or mp[{j + 2, k+2}] == 0) continue;
            ans = min(ans ,max({mp[{j , k}] , mp[{j , k+1}] , mp[{j , k+2}] , mp[{j + 1, k}] , mp[{j + 1, k+1}] , mp[{j + 1, k+2}] , mp[{j + 2, k}] , mp[{j + 2, k+1}] , mp[{j + 2, k+2}] })) ;
        }
    }
    if(ans == INT_MAX) ans = -1;
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