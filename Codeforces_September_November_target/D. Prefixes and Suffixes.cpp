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
void solve()
{
    long long n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    map<long long, long long> mp;
    for (long long i = 0; i < n; i++)
    {
        mp[min(s[i], t[n - i - 1]) * 100 + max(s[i], t[n - i - 1])]++;
    }
    long long cnt = 0;
    for (auto &x : mp)
    {
        // cout << x.first << " " << x.second << sad;
        if (x.second % 2)
        {
            cnt++;
            // cout << x.first % 100;
            if (x.first / 100 != x.first % 100)
            {
                na;
                return;
            }
        }
    }
    if (cnt > 1)
    {
        na;
    }
    else
    {
        ha;
    }
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