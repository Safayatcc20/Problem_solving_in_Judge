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
const long long N = 10000;
long long prime[N];
long long fact(long long n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}
void seive()
{
    prime[0] = prime[1] = 1;
    for (long long i = 2; i * i <= N; i++)
    {
        if (!prime)
        {
            for (long long j = i * i; j <= N; j += i)
            {
                prime[j] = 1;
            }
        }
    }
}
void solve()
{
    long long n, d;
    cin >> n >> d;
    long long m;
    cin >> m;
    while (m--)
    {
        /* code */
        long long x, y;
        cin >> x >> y;
        long long a = x + d, b = x - d, c = n - d;
        if (x < d)
        {
            if (y >= (d - x))
            {
                if (x + d > n)
                {
                    if (y <= (2 * n - d - x))
                    {
                        ha;
                    }
                    else
                    {
                        na;
                    }
                }
                else if (y <= (x + d))
                {
                    ha;
                }
                else
                {
                    na;
                }
            }
            else
            {
                na;
            }
        }
        else if (d <= x and x <= n - d)
        {
            if (y >= (x - d))
            {
                if (y <= x + d)
                {
                    ha;
                }
                else
                {
                    na;
                }
            }
            else
            {
                na;
            }
        }
        else if (x > n - d)
        {
            if (y >= (x - d))
            {
                if (y <= (2 * n - d - x))
                {
                    // cout << "get" << sad;
                    ha;
                }
                else
                {
                    na;
                }
            }
            else
            {
                na;
            }
        }
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