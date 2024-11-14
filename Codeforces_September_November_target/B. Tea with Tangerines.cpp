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
    bool flag = false;
    vector<long long> v(n);
    for (auto &x : v)
    {
        cin >> x;
        if (x == 1)
        {
            flag = true;
        }
    }
    if (n == 1)
    {
        cout << 0 << sad;
        return;
    }
    sort(all(v));
    long long ans = 0;
    for (long long i = 1; i < n; i++)
    {
        ans += ceil((v[i]) / (v[0] * 2.00 - 1)) - 1;
        // cout << ans << sad;
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