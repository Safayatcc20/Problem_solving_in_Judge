#include <bits/stdc++.h>
using namespace std;
bool visited[100000];
vector<long long> graph[1000] , dist(100000);
void bfs(long long source)
{
    queue<long long> q;
    visited[source] = 1;
    dist[source] = 0;
    q.push(source);
    cout << source << " " ;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (long long i = 0; i < graph[node].size(); i++)
        {
            long long next = graph[node][i];
            if (visited[next] == 0)
            {
                cout << next << " ";
                visited[next] = 1;
                q.push(next);
            }
        }
    }
}
int main()
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
    bfs(1);
}