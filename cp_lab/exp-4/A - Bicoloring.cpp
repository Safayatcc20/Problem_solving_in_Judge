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
const long long N= 1000;
stack<long long>s;
bool  bfs(long long source , vector<vector<long long>>&g){
    int vis[N];
    memset(vis , -1 , sizeof(vis));
    vis[source] = 0;
    queue<int>q;
    q.push(source);
    while(q.size()){
        int node = q.front();
        q.pop();
        for(int i = 0 ;  i < g[node].size(); i++){
            int next = g[node][i];
            if(vis[next] == -1){
                q.push(next);
                vis[next] = 1 - vis[node];
            }
            else if(vis[next] == vis[node]){
                return false;
            }
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    //cin >> t;
    long long n , m;
    
    while (cin >> n)
    {
        if(n == 0) return 0;
        cin >> m;
        vector<vector<long long>>g(n+2);
        for(long long i =  0; i < m ;i++){
            long long u , v;
            cin>> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(!bfs(0 , g)){
            cout << "NOT ";
        }
        cout << "BICOLORABLE." << sad;
    }
}