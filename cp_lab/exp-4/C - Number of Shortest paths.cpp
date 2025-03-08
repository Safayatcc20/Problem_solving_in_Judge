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
const int N = 2e5+10;
long long ans = 0 ;
vector<int>g[N];
bool vis[N];
int path[N];
int dist[N];
int n  , m;
const long long mod = 1e9+7;
void bfs(int source){
    vis[source] = true;
    queue<int>q;
    q.push(source);
    path[source] = 1;
    dist[source] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto &ad:g[node]){
            if(vis[ad] == false){
                q.push(ad);
                vis[ad] = true;
                path[ad] = path[node];
                dist[ad] = dist[node]+1;
            }
            else if(dist[ad] == dist[node] + 1){
                path[ad]=(path[ad] + path[node]) % mod; 
            }
        }
    }
}
void solve(){
    cin >> n >> m;
    for(int i = 0 ; i < m; i++){
        int x , y ;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    if(m == 0){
        cout << 0 << sad;
        return;
    }
    bfs(1);
    cout << path[n] << sad;
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
        ans = 0;
        solve();
    }
}