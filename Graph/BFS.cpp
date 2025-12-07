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
long long gcd(long long x, long long y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
long long lcm(long long x, long long y)
{
    return ((x * y) / gcd(x, y));
}
bool visited[100000];
long long dist[100000];
vector<long long> graph[1000];
void bfs(long long source)
{
    queue<long long> q;
    visited[source] = 1;
    dist[source] = 0;
    q.push(source);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (long long i = 0; i < graph[node].size(); i++)
        {
            long long next = graph[node][i];
            if (visited[next] == 0)
            {
                visited[next] = 1;           // visit
                dist[next] = dist[node] + 1; // 1 for edge cost if 1;//update
                q.push(next);                // push to queue
            }
        }
        /* code */
    }
}
void solve()
{
    long long node, edge;
    cin >> node >> edge;
    for (long long i = 1; i <= edge; i++)
    {
        long long u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int source;
    cin >> source;
    bfs(source);
    cout << "From node " << source << sad;
    for (long long i = 1; i <= node; i++)
    {
        cout << "Distance of " << i << " is " << dist[i] << sad;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // long long t;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}