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
    long long n, m;
    cin >> n >> m;
    long long cnt = 0;
    long long take = (sqrtl(n));
    long long out = (sqrtl(m));
    cnt = (out - take) * 3;
    if (cnt < 0)
    {
        cnt = 0;
    }
    long long a = llround(take * take);
    long long x = llround(out * out);
    long long b = (take + 1) * take;
    long long c = (take + 2) * take;
    long long y = (out + 2) * out;
    long long z = (out + 1) * out;
    // cout << a << " " << b << " " << c << sad;
    // cout << x << " " << y << " " << z << sad;
    if (a < n)
    {
        cnt--;
    }
    if (b < n)
    {
        cnt--;
    }
    if (c < n)
    {
        cnt--;
    }
    if (x > m)
    {
        cnt--;
    }
    if (y > m)
    {
        cnt--;
    }
    if (z > m)
    {
        cnt--;
    }
    cout << cnt + 3 << sad;
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