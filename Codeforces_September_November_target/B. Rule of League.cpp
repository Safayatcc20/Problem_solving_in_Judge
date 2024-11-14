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
    long long n, x, y;
    cin >> n >> x >> y;
    if (y == 0 && x == 0)
    {
        cout << -1 << sad;
        return;
    }
    if (y != 0 && x != 0)
    {
        cout << -1 << sad;
        return;
    }
    if (y == 0)
    {
        if ((n - 1) % x)
        {
            cout << -1 << sad;
        }
        else
        {
            long long ans = 1;
            for (long long i = 0; i < n - 1; i++)
            {
                if (x == y)
                {
                    y = 0;
                    ans = i + 2;
                }
                y++;
                cout << ans << " ";
            }
            cout << sad;
        }
    }
    else
    {
        if ((n - 1) % y)
        {
            cout << -1 << sad;
        }
        else
        {
            long long ans = 1;
            for (long long i = 0; i < n - 1; i++)
            {
                if (x == y)
                {
                    x = 0;
                    ans = i + 2;
                }
                x++;
                cout << ans << " ";
            }
            cout << sad;
        }
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