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
const long long N = 1e6+10;
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
bool vis[N];
long long ans = 0, cnt = 0 ;
void dfs(long long source,vector<vector<long long>>&g , long long m , vector<long long>&v , long long chk){
    vis[source] = true;
    if(chk > m) return;
    bool flag = true;
    for(auto x:g[source]){
        if(!vis[x]){
            flag = false;
            dfs(x , g , m , v , chk *v[x] + v[x]);
        }
    }
    if(flag) {ans++;}
}
void solve(){
    long long n , m;
    cin >> n >> m; 
    vector<long long>v(n+1);
    for(long long i = 1; i <= n  ; i++){
        cin >> v[i];
    }
    vector<vector<long long>>g(n+1);
    for(long long i = 0 ; i < n-1; i++){
        long long u , v;
        cin >> u >> v;
        g[u].push_back(v);
        //g[v].push_back(u);
    }
    dfs(1 , g  , m , v , v[1]);
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