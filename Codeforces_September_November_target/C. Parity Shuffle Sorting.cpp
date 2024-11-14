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
    vector<long long> a(n);
    for (auto &x : a)
        cin >> x;
    if (n == 1)
    {
        cout << 0 << sad;
        return;
    }
    if (is_sorted(all(a)))
    {
        cout << 0 << sad;
        return;
    }
    if ((a[0] + a[n - 1]) % 2)
    {
        a[n - 1] = a[0];
    }
    else
    {
        a[0] = a[n - 1];
    }
    vector<pair<long long, long long>> p;
    p.push_back({1, n});
    // cout << 1 << " " << n << sad;
    long long cnt = 0;
    for (long long i = 1; i < n - 1; i++)
    {
        if (a[0] & 1)
        {
            if (a[i] & 1)
            {
                p.push_back({i + 1, n});
                // cout << 1 << " " << i + 1 << sad;
            }
            else
            {
                cnt++;
                p.push_back({1, i + 1});
                // cout << i + 1 << " " << n << sad;
            }
        }
        else
        {
            if (a[i] % 2 == 0)
            {
                p.push_back({i + 1, n});
                // cout << 1 << " " << i + 1 << sad;
            }
            else
            {
                p.push_back({1, i + 1});
                // cout << i + 1 << " " << n << sad;
            }
        }
    }
    cout << p.size() << sad;
    for (auto &x : p)
    {
        cout << x.first << " " << x.second << sad;
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