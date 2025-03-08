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
bool visited[100000];
long long dist[100000];
vector<pair<long long , long long>> graph[100000];
void bfs(long long source)
{
    queue<long long> q;
    visited[source] = 1;
    dist[source] = 0;
    q.push(source);
    while (!q.empty())
    {
        int node = q.front();
        //cout << node << sad;
        q.pop();
        for (long long i = 0; i < graph[node].size(); i++)
        {
            long long next = graph[node][i].first;
            //cout << next << sad;
            if (visited[next] == 0)
            {
                visited[next] = 1;           
                dist[next] = dist[node] + graph[node][i].second; 
                q.push(next);           
            }
        }
    }
}
void solve()
{
    long long node, edge;
    cin >> node ;
    
    memset(graph , 0 , sizeof(graph));
    memset(visited , 0 , sizeof(visited));
    memset(dist , 0 , sizeof(dist));
    for (long long i = 1; i < node; i++)
    {
        long long u, v , w;
        cin >> u >> v >> w;
        graph[u].push_back({v , w});
        graph[v].push_back({u , w});
    }
    bfs(0);
    long long ans = INT_MIN, farthest_node;
    for (long long i = 0; i < node; i++)
    {
        //cout << "Distance of " << i << " is " << dist[i] << sad;
        if(dist[i] > ans){
            ans = dist[i];
            farthest_node = i;
        }
    }
    //cout << farthest_node << sad;
    memset(visited , 0 , sizeof(visited));
    memset(dist , 0 , sizeof(dist));
    bfs(farthest_node);
    ans = 0 ;
    for (long long i = 0; i < node; i++)
    {
        //cout << "Distance of " << i << " is " << dist[i] << sad;
        if(dist[i] > ans){
            ans = dist[i];
            farthest_node = i;
        }
    }
    cout << ans << sad;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // long long t;
    cin >> t;
    int i = 1;
    while (t--)
    {
        cout << "Case " << i << ": " ;
        i++;
        solve();
    }
}