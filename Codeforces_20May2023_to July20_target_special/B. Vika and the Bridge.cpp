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
    int n , k;
    cin >> n >> k;
    vector<int>c(n);
    for(auto &x:c) cin >> x;
    vector<vector<int>>v(k);
    vector<int>vis(k, -1);
    for(int i = 0 ; i < n ;i++){
        v[c[i]-1].push_back(i - vis[c[i]-1] - 1);
        vis[c[i]-1] = i;
    }
    int ans = INT_MAX;
    for(int i = 0 ; i < k ; i++){
        v[i].push_back(n - vis[i] - 1);
        sort(v[i].begin() , v[i].end());
    }
    for(int i = 0 ; i < k ; i++){
        const auto &create = v[i];
        if(!create.empty()){
            int chk = 0 ;
            if(create.size() > 1) chk = create[create.size()-2];
            int store = max(create.back()/ 2  , chk);
            ans = min(ans , store);
        }
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
    cin >> t;
    while (t--)
    {
        solve();
    }
}