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
vector<long long> adj[1000000];
bool visited[1000000];
  
bool dfs(int start, int end)
{
    if (start == end)
        return true;
    visited[start] = 1;
    for (auto x : adj[start]) {
        if (!visited[x])
            if (dfs(x, end))
                return true;
    }
    return false;
}
void solve(){
    long long n , m;
    cin >>  n >> m;
    for(long long i = 0 ; i < m; i++){
        long long u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(long long i = 1; i < n; i++){
        if(dfs(i , i+1)){
            continue;
        }
        else if(dfs(i+1, i)){
            continue;
        }
        else{
            cout << "No" << sad;
            return;
        }
    }
    cout << "Yes" << sad;
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