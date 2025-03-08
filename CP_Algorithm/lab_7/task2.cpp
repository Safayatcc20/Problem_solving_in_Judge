#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
const int INF = 1e9+10;
vector<pair<int , int>> g[N];
vector<int>dist(N, INF);
void dijkstra(int source , int n){
    vector<int>vis(N,0);
    set<pair<int,int>>s;
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
}
int main()
{
    int n  , m;
    cin >> n >> m;
    for(int i = 0 ; i < m; i++){
        int u , v , w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    int source , dest;
    cin >> source >> dest;
    dijkstra(source , dest);
    cout << dist[dest] << endl;
}