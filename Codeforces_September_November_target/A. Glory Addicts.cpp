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
    long long sum = 0, zero = 0, one = 0;
    vector<long long> v(n), vv(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] == 0)
        {
            zero++;
        }
        else
        {
            one++;
        }
    }
    long long mn = INT_MAX;
    for (long long i = 0; i < n; i++)
    {
        cin >> vv[i];
        sum += vv[i];
        mn = min(mn, vv[i]);
    }
    if (one == n || zero == n)
    {
        cout << sum << sad;
        return;
    }
    if (one == zero)
    {
        sum = 0;
        sum += vv[0];
        for (long long i = 1; i < n; i++)
        {
            sum += vv[i] * 2;
        }
        cout << sum << sad;
        return;
    }
    sum = 0;
    sum += vv[n - 1] * 2;
    for (long long i = 0; i < n - 1; i++)
    {
        if (v[i] != v[i + 1])
        {
            sum += vv[i] * 2;
        }
        else
        {
            sum += vv[i];
        }
    }
    cout << sum << sad;
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