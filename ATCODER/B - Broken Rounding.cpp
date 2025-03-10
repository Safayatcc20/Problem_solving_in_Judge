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
    long long x;
    int k;
    cin >> x >> k;
    long long ans = llround(pow(10, k));
    int cnt = 0, y = ceil(log10(x));
    long long remind = llround(pow(10, y - 1));

    long long n = (x / (ans)) * ans;
    long long m = ans + n;
    if ((m - x) - (x - n) <= 4)
    {
        cout << m << sad;
    }
    else
    {
        long long chk = x - n;
        if ((m - x) < chk)
        {
            cout << m << sad;
        }
        else
        {
            cout << n << sad;
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