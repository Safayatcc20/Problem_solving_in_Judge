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
    long long zero = 0;
    vector<pair<long long, long long>> v(n);
    for (long long i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        v.push_back({x, 0});
    }
    if (n == 1)
    {
        cout << 0 << sad;
        return;
    }
    if (zero == n)
    {
        double ans = 0;
        for (long long i = 0; i < n; i++)
        {
            ans += v[i].first;
        }
        cout << fixed << setprecision(1) << ans / n << sad;
        return;
    }
    long long mn = INT_MAX, index = -1;
    for (long long i = 0; i < n; i++)
    {
        long long ans = 0;
        for (long long j = 0; j < n; j++)
        {
            ans += v[j].second + abs(v[j].first - v[i].first);
        }
        if (ans < mn)
        {
            index = i;
        }
    }
    cout << index + 1 << sad;
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