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
    seive();
    int n;
    cin >> n;
    vector<int> v;
    map<int, int> mp;
    set<int> s;
    for (long long i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
        mp[x] = i;
    }
    v.assign(all(s));
    int ans = -1;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i; j < v.size(); j++)
        {
            if (gcd(v[j], v[i]) == 1)
            {
                ans = max(ans, mp[v[j]] + mp[v[i]]);
            }
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
    while (t--)
    {
        solve();
    }
}