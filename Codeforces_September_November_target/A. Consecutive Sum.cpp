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
    long long n, k;
    cin >> n >> k;
    vector<long long> v(n), ind;
    for (auto &x : v)
        cin >> x;

    ind.assign(all(v));
    for (long long i = 0; i < n; i++)
    {
        ind[i % k] = max(ind[i % k], v[i]);
    }
    long long sum = 0;
    for (long long i = 0; i < k; i++)
    {
        sum += ind[i];
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