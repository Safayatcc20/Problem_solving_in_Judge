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
const long long N = 3 * 1e5;
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
vector<int>depth(N);
void dfs(int node , vector<vector<int>>&g , int par =-1){
    for(auto &child: g[node]){
        if(child == par) continue;
        depth[child] = depth[node]+ 1;
        dfs(child , g , node);
    }
}
void solve(){
    int n ;
    cin >> n;
    vector<vector<int>>g(n+1);
    for(int i = 0 ; i < n - 1; i++){
        int x , y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1 , g);
    int mx_depth= -1;
    int mx_node;
    for(int i = 1; i <= n ; i++){
        
        if(mx_depth <= depth[i]){
            mx_depth = depth[i];
            mx_node = i;
        }
        depth[i] = 0 ;
    }
    dfs(mx_node , g);
    mx_depth= -1;
    for(int i = 1; i <= n ; i++){
        //cout << i << " " << depth[i] << sad;
        if(mx_depth <= depth[i]){
            mx_depth = depth[i];
            mx_node = i;
        }
    }
    //cout << mx_depth  << sad;
    for(int i = 1; i <= n ; i++){
        if(depth[i] == 0){
            cout << mx_depth+ 1 << sad;
        }
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