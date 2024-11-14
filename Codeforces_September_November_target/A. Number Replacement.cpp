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
    long long n;
    cin >> n;
    set<long long> ss;
    map<long long, set<char>> mp;
    vector<long long> v(n);
    for (auto &x : v)
    {
        cin >> x;
        ss.insert(x);
    }
    string s;
    cin >> s;
    for (long long i = 0; i < n; i++)
    {
        mp[v[i]].insert(s[i]);
        // cout << mp[v[i]].size() << sad;
    }
    for (auto &x : v)
    {
        // cout << mp[x].size() << sad;
        if (mp[x].size() > 1)
        {
            na;
            return;
        }
    }
    ha;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}