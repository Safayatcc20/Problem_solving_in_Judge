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
    long long n, q;
    cin >> n >> q;
    vector<vector<long long>> v;
    for (long long i = 1; i <= n; i++)
    {
        long long l;
        cin >> l;
        vector<long long> vv(l + 1);
        for (long long j = 1; j <= l; j++)
        {
            cin >> vv[j];
        }
        v.push_back(vv);
    }
    // cout << a[1][1] << sad;
    while (q--)
    {
        long long s, t;
        cin >> s >> t;
        cout << v[s - 1][t] << sad;
    }
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