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
// Solving a problem using DFS;
// directed graph;
bool visited[100010];
vector<long long> graph[100010];
void dfs(long long source)
{
    visited[source] = 1;
    for (long long i = 0; i < graph[source].size(); i++)
    {
        long long next = graph[source][i];
        if (visited[next] == 0)
        {
            dfs(next);
        }
    }
}
void solve()
{
    long long n, t;
    cin >> n >> t;
    for (long long i = 1; i <= n - 1; i++)
    {
        long long u;
        cin >> u;
        graph[i].push_back(u + i);
    }
    dfs(1);
    if (visited[t] == 1)
    {
        ha;
    }
    else
    {
        na;
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