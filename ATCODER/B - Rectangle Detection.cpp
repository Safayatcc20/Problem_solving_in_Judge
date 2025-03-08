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
    char s[11][11];
    for (long long i = 0; i < 10; i++)
    {
        for (long long j = 0; j < 10; j++)
        {
            cin >> s[i][j];
        }
    }
    long long a = -1, b, c = -1, d;
    for (long long i = 0; i < 10; i++)
    {
        for (long long j = 0; j < 10; j++)
        {
            if (s[i][j] == '#' && a == -1 && c == -1)
            {
                a = i + 1;
                c = j + 1;
            }
            if (s[i][j] == '#')
            {
                b = i + 1;
                d = j + 1;
            }
        }
    }
    cout << a << " " << b << sad;
    cout << c << " " << d << sad;
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