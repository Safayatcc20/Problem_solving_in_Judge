#include <bits/stdc++.h>
using namespace std;
bool visited[100000];
long long dist[100000];
vector<long long> graph[1000];
void dfs(long long source)
{
    visited[source] = true;
    for(auto &next:graph[source]){
        if(visited[next]) continue;
        cout << next << " ";
        dfs(next);
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
    cout  << 1 << " "; dfs(1);
}