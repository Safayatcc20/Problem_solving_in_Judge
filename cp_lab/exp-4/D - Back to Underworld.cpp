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
long long chk[100000];
vector<long long> graph[100000];
long long bfs(long long source)
{
    queue<long long> q;
    visited[source] = 1;
    chk[source] = 1;
    q.push(source);
    long long vam = 1 , lyk = 0 ;
    while (!q.empty())
    {
        long long node = q.front();
        q.pop();
        for (auto &next:graph[node])
        {
            if (visited[next] == 0)
            {
                if(chk[node]){
                    chk[next] = 0 ;
                    lyk++;
                }
                else{
                    chk[next] = 1;
                    vam++;
                }
                visited[next] = 1;           
                q.push(next);
            }
        }
    }
    return max(vam , lyk);
}
void solve()
{
    long long node, edge;
    cin >> node ;
    
    memset(graph , 0 , sizeof(graph));
    memset(visited , 0 , sizeof(visited));
    memset(chk , 0 , sizeof(chk));
    set<int>s;
    
    for (long long i = 1; i <= node; i++)
    {
        long long u, v ;
        cin >> u >> v ;
        s.insert(u);
        s.insert(v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    long long ans = 0;
    for (auto &i:s)
    {
        if(!visited[i]){
            ans += bfs(i);
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