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
    long long x, y, z, n;
    cin >> x >> y >> z >> n;
    if (x == y && y == z)
    {
        if (n % 3)
        {
            na;
        }
        else
        {
            ha;
        }
        return;
    }
    /*if (x == y && x > z)
    {
        n -= (x - z);
        if (n % 2)
        {
            na;
        }
        else
        {
            ha;
        }
        return;
    }
    if (x == y && x < z)
    {
        n -= z;
        if (n % 2)
        {
            na;
        }
        else
        {
            ha;
        }
        return;
    }
    if (x == z && x > y)
    {
        n -= (x - y);
        if (n % 2)
        {
            na;
        }
        else
        {
            ha;
        }
        return;
    }
    if (x == z && x < y)
    {
        n -= y;
        if (n % 2)
        {
            na;
        }
        else
        {
            ha;
        }
        return;
    }
    if (z == y && y > x)
    {
        n -= (z - x);
        if (n % 2)
        {
            na;
        }
        else
        {
            ha;
        }
        return;
    }
    if (z == y && x > z)
    {
        n -= x;
        if (n % 2)
        {
            na;
        }
        else
        {
            ha;
        }
        return;
    } */
    long long mx = max({x, y, z});
    x = mx - x;
    y = mx - y;
    z = mx - z;
    if (x == 0)
    {
        n -= (y + z);
        if (n % 3 || n < 0)
        {
            na;
        }
        else
        {
            ha;
        }
    }
    else if (y == 0)
    {
        n -= (x + z);
        if (n % 3 || n < 0)
        {
            na;
        }
        else
        {
            ha;
        }
    }
    else if (z == 0)
    {
        n -= (y + x);
        if (n % 3 || n < 0)
        {
            na;
        }
        else
        {
            ha;
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