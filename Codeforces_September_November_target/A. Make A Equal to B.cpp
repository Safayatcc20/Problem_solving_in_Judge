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
    long long one = 0, zero = 0, z = 0, o = 0;
    vector<long long> a(n), b(n), aa(n), bb(n);
    map<long long, long long> ma, mb;
    set<long long> sa, sb;
    for (auto &x : a)
    {
        cin >> x;
        ma[x]++;
    }
    for (auto &x : b)
    {
        cin >> x;
        mb[x]++;
    }
    long long cnt = 0;
    for (long long i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            cnt++;
        }
    }
    // cout << cnt << sad;
    if (a == b)
    {
        cout << 0 << sad;
        return;
    }

    aa = a;
    bb = b;
    sort(all(aa));
    sort(all(bb));
    if (aa == bb)
    {
        cout << 1 << sad;
        return;
    }
    cout << min(cnt, abs((ma[0] - mb[0])) + 1) << sad;
    ;
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