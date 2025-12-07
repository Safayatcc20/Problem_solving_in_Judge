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
const long long N= 1e7+10;
stack<long long>s;
bool vis[N];
long long ans = 0 ;
void dfs(long long source , vector<vector<long long>>&g){
    vis[source] = true;
    for(long long i = 0 ; i < g[source].size(); i++){
        if(vis[g[source][i]] == false){
            dfs(g[source][i] , g);
        }
    }
}
void solve(){
    //dfs solution
    // finding the connected component then counting edges - node + connected component which is answer
    long long n , m;
    cin >> n >> m;
    vector<vector<long long>>g(n+2);
    for(long long i =  0; i < m ;i++){
        long long u , v;
        cin>> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    long long k = 0;
    for(long long i = 1; i <= n; i++){
        if(!vis[i]){
            k++;
            dfs(i , g);
        }
    }
    cout << m-n + k << sad;
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