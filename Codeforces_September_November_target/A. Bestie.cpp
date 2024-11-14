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
    vector<long long> v(n + 1);
    for (long long i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    long long ans = 0;
    if (n == 1)
    {
        if (v[1] == 1)
        {
            cout << 0 << sad;
        }
        else
        {
            cout << 1 << sad;
        }
        return;
    }
    ans = v[1];
    for (long long i = 2; i <= n; i++)
    {
        ans = gcd(ans, v[i]);
    }
    if (ans == 1)
    {
        cout << 0 << sad;
        return;
    }
    long long done = 0, cnt = 0;
    for (long long i = n; i > 0; i--)
    {
        ans = gcd(v[i], i);
        for (long long j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            ans = gcd(ans, v[j]);
        }
        // cout << i << " " << ans << sad;
        if (ans == 1 || cnt > 1)
        {
            // cout << i << sad;
            done = n - i + 1;
            break;
        }
        cnt++;
    }
    cout << done << sad;
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