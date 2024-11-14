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
    vector<long long> v(n), vv(n);
    vector<pair<long long, long long>> pr(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (long long i = 0; i < n; i++)
    {
        cin >> vv[i];
    }
    for (long long i = 0; i < n; i++)
    {
        pr[i] = {vv[i], v[i]};
    }
    sort(all(pr));
    long long ans = 0;
    /* for (long long i = 0; i < n; i++)
        cout << pr[i].first << " " << pr[i].second << sad; */
    for (long long i = 0; i < n; i++)
    {
        ans += pr[i].second;
        if (i == n - 1)
            continue;
        pr[i + 1].second += (pr[i].first);
    }
    cout << ans << sad;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}