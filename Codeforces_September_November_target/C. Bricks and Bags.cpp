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
    long long n;
    cin >> n;
    vector<long long> v(n), ft, sec, thd;
    for (auto &x : v)
        cin >> x;
    sort(all(v));
    long long ans = 0;
    for (long long i = n - 1; i > 0; i--)
    {
        ans = max(ans, (v[i] - v[0]) + (v[i] - v[i - 1]));
    }
    for (long long i = 0; i < n - 1; i++)
    {
        // cout << abs(v[n - 1] - v[i]) + (abs(v[n - 1] - v[i + 1])) << sad;
        ans = max(ans, abs(v[n - 1] - v[i]) + (abs(v[i + 1] - v[i])));
    }
    cout << ans << sad;
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