#include <bits/stdc++.h>
using namespace std;
bool visited[10000000];
long long dist[10000000];
vector<long long> graph[10000];
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
                visited[next] = 1;         
                dist[next] = dist[node] + 1; 
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
        graph[u].push_back(v) , graph[v].push_back(u);
    }
    int source , dest;
    cin >> source >> dest;
    bfs(source);
    cout << dist[dest] << endl;
}