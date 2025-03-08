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
bool visited[1000005];
long long dist[1000005];
vector<long long> graph[1000005];
int n , m;
vector<long long>v;
void bfs(long long source)
{
    queue<long long> q;
    visited[source] = 1;
    dist[source] = 0;
    q.push(source);
    while (!q.empty())
    {
        long long node = q.front();
        q.pop();
        for (auto &next:graph[node])
        {
            if (visited[next] == 0)
            {
                visited[next] = 1;           
                dist[next] = dist[node] + 1;
                q.push(next); 
                if(next == n){
                    v.push_back(node);
                }          
            }
        }
    }
}
void solve(){
    cin >> n >> m;
    for(int i = 0 ;i < m  ; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1; i <= n ; i++){
        if(!visited[i]){
            bfs(i);
        }
    }
    cout << "Distance: " << dist[n] << endl;
    cout << "Path: ";
    cout << 1 << " ";
    for(auto &x:v){
        cout << x << " ";
    }
    cout << n << endl;
    /* for(int i = 1; i <= n ;i++){
        cout << dist[i] << endl;
    } */
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