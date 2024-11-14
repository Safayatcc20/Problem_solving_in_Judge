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
    char a[8][8];
    char ans = '\0', take;
    int index = -1;
    int r = 0, b = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'R')
            {
                r = 1;
            }
            if (a[i][j] == 'B')
            {
                b = 1;
            }
        }
    }
    map<char, long long> mp;
    for (int i = 0; i < 8; i++)
    {
        r = 0;
        for (int j = 0; j < 8; j++)
        {
            if (a[i][j] == 'R')
            {
                r++;
            }
        }
        if (r == 8)
        {
            break;
        }
    }
    if (r == 8)
    {
        cout << "R" << sad;
    }
    else
    {
        cout << "B" << sad;
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