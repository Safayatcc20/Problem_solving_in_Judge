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
const long long N = 10000;
long long prime[N];
void seive()
{
    prime[0] = prime[1] = 1;
    for (long long i = 2; i * i <= N; i++)
    {
        if (!prime)
        {
            for (long long j = i * i; j <= N; j += i)
            {
                prime[j] = 1;
            }
        }
    }
}
void solve()
{
    int s, n;
    cin >> s >> n;
    bool flag = true;
    vector<pair<int, int>> mp;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        mp.push_back({x, y});
    }
    sort(all(mp));
    for (auto &x : mp)
    {
        if (x.first < s)
        {
            s += x.second;
        }
        else
        {
            flag = false;
            break;
        }
    }
    if (flag)
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