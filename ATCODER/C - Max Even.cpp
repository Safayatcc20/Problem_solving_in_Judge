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
    vector<long long> even, odd;
    for (long long i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        if (x & 1)
        {
            odd.push_back(x);
        }
        else
        {
            even.push_back(x);
        }
    }
    if (odd.size() == 1 && even.size() == 1)
    {
        cout << -1 << sad;
        return;
    }
    sort(all(even));
    sort(all(odd));
    long long mx = 0;
    // cout << even[even.size() - 1] + even[even.size() - 2] << sad;
    if (even.size() > 1)
    {
        mx = max(mx, even[even.size() - 1] + even[even.size() - 2]);
    }
    if (odd.size() > 1)
    {
        mx = max(mx, odd[odd.size() - 1] + odd[odd.size() - 2]);
    }
    cout << mx << sad;
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