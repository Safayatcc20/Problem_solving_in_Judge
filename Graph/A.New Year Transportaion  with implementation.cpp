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
long long n;
bool visited[100010];
vector<long long> graph[100010];
map<long long, long long> mp;
void good(long long nn)
{
    visited[nn] = 1;
    // cout << next << sad;
    if (mp[nn])
    {
        long long next = mp[nn];
        visited[next] = 1;
        good(mp[next]);
    }
}
void solve()
{
    long long t;
    cin >> n >> t;
    for (long long i = 1; i < n; i++)
    {
        long long x;
        cin >> x;
        mp[i] = x + i;
    }
    good(1);
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