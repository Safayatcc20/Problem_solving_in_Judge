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
    vector<long long> make(n + 1), uni, pre(n + 1), v(n + 1);
    map<long long, long long> mp;
    set<long long> s;
    long long take = 0;
    for (long long i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (long long i = 1; i <= n; i++)
    {
        make[i] = max(make[i - 1], v[i]);
        pre[i] = pre[i - 1] + v[i];
    }
    while (q--)
    {
        long long x;
        cin >> x;
        if (x == 0)
        {
            cout << 0 << " ";
            continue;
        }
        long long y = upper_bound(all(make), x) - make.begin();
        cout << pre[y - 1] << " ";
    }
    cout << sad;
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