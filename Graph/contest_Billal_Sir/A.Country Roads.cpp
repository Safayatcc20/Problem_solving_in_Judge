/*
 **** Bismillahir Rahmanir Rahim ****
 */
 
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
const int N = 1e6+10;
const int INF = 1e8+10;
/*void dijkstra(int source , int n ){
    vector<int>vis(N,0);
    vector<int>dist(N, INF);
    set<pair<int,int>>s;//first value weight , second node;

    s.insert({0 , source});    
    dist[source] = 0;
    int chk = 0;
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
            chk = max(wt , dist[v]);
            if( chk < dist[childv]){
                dist[childv] = chk;
                cout << v << " " << childv << " " << dist[childv] << sad;
                s.insert({dist[childv], childv});
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n ; i++){
        if(dist[i] == INF) {cout << "Impossible" << sad;continue;}
        cout << dist[i] << sad;
    }
    //complexity (V + E log(v));
}*/
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long t;
    cin >> t;
    int i = 1;
    while (t--)
    {
        cout << "Case " << i << ": " << sad;
        i++;
        int n  , m;
        cin >> n >> m;
        vector<pair<int , int>> g[n+m];
        for(int i = 0 ; i < m; i++){
            int u , v , w;
            cin >> u >> v >> w;
            g[u].push_back({v, w});// undirected graph;
            g[v].push_back({u, w});// undirected graph;
        }
        long long q;
        cin >> q;
        vector<int>vis(N,0);
        vector<int>dist(N, INF);
        set<pair<int,int>>s;//first value weight , second node;

        s.insert({0 , q});    
        dist[q] = 0;
        int chk = 0;
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
                chk = max(wt , dist[v]);
                if( chk < dist[childv]){
                    dist[childv] = chk;
                    //cout << v << " " << childv << " " << dist[childv] << sad;
                    s.insert({dist[childv], childv});
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n ; i++){
            if(dist[i] == INF) {cout << "Impossible" << sad;continue;}
            cout << dist[i] << sad;
        }
    }
}