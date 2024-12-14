 
 /***** Bismillahir Rahmanir Rahim *****/
 
#include <bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T> using oset = tree<T , null_type , less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define int long long
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
bool comp(pair<int , int>&a , pair<int , int>&b){
    return a.first - a.second < b.first - b.second;
}
void solve(){
    int n;
    cin>> n;
    vector<int>p(n) , q(n) , s(n) , r(n);
    vector<int>shb;
    for(auto &x:p) cin >> x;
    for(auto &x:q) cin >> x;
    for(auto &x:r) cin >> x;
    for(auto &x:s) cin >> x;
    vector<pair<int , int>>v(n);
    for(int i = 0 ; i < n ;i++){
        v[i] = {p[i] , q[i]};
    }
    for(int i = 1 ; i < n ;i++){
        s[i] += s[i-1]; 
        r[i] += r[i-1]; 
    }
    sort(all(v) , comp);
    int ans = 1e18 ,Ichigo = 0, Rukia= 0;
    for(int i = 0; i < n; i++){
        Rukia+= v[i].second;
    }
    ans = min(ans , Rukia + s[n-1]);
    for(int i = 0; i < n; i++){
        Ichigo+=v[i].first;
        Rukia-=v[i].second;
        ans =  min( ans , Ichigo + Rukia + r[i] + s[n-i-2]);
    }
    ans = min(ans , Ichigo + r[n-1]);
    cout << ans << sad;
    
}
int32_t main()
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