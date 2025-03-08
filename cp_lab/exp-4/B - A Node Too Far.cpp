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
vector<long long >g[N];
bool vis[N];
long long dist[N];
long long n  , m;

long long bfs(long long source , long long y){
    vis[source] = true;
    queue<long long>q;
    q.push(source);
    while(!q.empty()){
        long long node = q.front();
        q.pop();
        for(auto &ad:g[node]){
            if(vis[ad] == false){
                q.push(ad);
                vis[ad] = true;
                dist[ad] = dist[node] + 1;
                if(dist[ad] <= y) ans++;
            }
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n , cas = 1;
    while (cin >> n)
    {
        if(n == 0){
            break;
        }
        set<long long>s;
        while(n--){
            long long u  , v;
            cin >> u >> v;
            s.insert(u);
            s.insert(v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        long long x , y;
        while(cin >> x >> y){
            if(x == 0 and y == 0) break;
            cout << "Case " << cas << ": ";
            cas++;
            cout << s.size() - bfs(x , y) - 1<< " nodes not reachable from node " << x << " with TTL = " << y << ".\n";
            //cout << x << " " << y << endl;
            //cout << bfs(x, y) << endl;
            //cout << s.size()  << endl;
            memset(vis , 0 , sizeof(vis));
            memset(dist , 0 , sizeof(dist));
            ans = 0 ;
        }
        memset(g , 0 , sizeof(g));
    }
}