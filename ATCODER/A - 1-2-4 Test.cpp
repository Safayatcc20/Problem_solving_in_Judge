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
    long long a, b;
    cin >> a >> b;
    if (a == 0 && b == 0)
    {
        cout << 0 << sad;
        return;
    }
    long long ans = 0;
    if (a == 1 || b == 1 || a == 3 || b == 3 || a == 5 || b == 5 || a == 7 || b == 7)
    {
        ans += 1;
    }
    if (a == 2 || b == 2 || a == 3 || b == 3 || a == 6 || b == 6 || a == 7 || b == 7)
    {
        ans += 2;
    }
    if (a == 4 || b == 4 || a == 5 || b == 5 || a == 6 || b == 6 || a == 7 || b == 7)
    {
        ans += 4;
    }
    cout << ans << sad;
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