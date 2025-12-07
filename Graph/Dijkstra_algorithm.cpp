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
const int N = 1e5+10;
const int INF = 1e9+10;
vector<pair<int , int>> g[N];
int dijkstra(int source , int n){
    vector<int>vis(N,0);
    vector<int>dist(N, INF);
    set<pair<int,int>>s;//first value weight , second node;

    s.insert({0 , source});    
    dist[source] = 0;
    while(s.size() > 0){
        auto node = *s.begin();
        int v = node.second;
        s.erase(s.begin());
        if(vis[v] ) continue;
        vis[v] = 1;
        int dis = node.first;
        for(auto child:g[v]){
            int childv = child.first;
            int wt = child.second;
            if(dist[v] + wt < dist[childv]){
                dist[childv] = dist[v] + wt;
                s.insert({dist[childv], childv});
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n ; i++){
        if(dist[i] == INF) return - 1;
        ans = max(ans , dist[i]);
    }
    return ans ;
    //complexity (E + Vlog(v));
}
void solve(){
    int n  , m;
    cin >> n >> m;
    for(int i = 0 ; i < m; i++){
        int u , v , w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});// directed graph;
        //g[u].push_back({v, w});// undirected graph;
        //g[v].push_back({u, w});// undirected graph;
    }
    cout << dijkstra(2 , n);
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