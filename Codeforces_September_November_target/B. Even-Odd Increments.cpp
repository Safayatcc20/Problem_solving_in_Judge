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
    long long n, q;
    cin >> n >> q;
    long long odd = 0, even = 0;
    vector<long long> v(n), pre(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] & 1)
        {
            odd++;
        }
        else
        {
            even++;
        }
    }
    pre[0] = v[0];
    long long sum = v[0];
    for (long long i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + v[i];
        sum += v[i];
    }
    while (q--)
    {
        long long t, x;
        cin >> t >> x;
        if (t == 1)
        {
            if (x & 1)
            {
                sum += (x * odd);
                even += odd;
                odd = 0;
            }
            else
            {
                sum += (x * odd);
            }
        }
        if (t == 0)
        {
            if (x & 1)
            {
                sum += (x * even);
                odd += even;
                even = 0;
            }
            else
            {
                sum += (x * even);
            }
        }
        cout << sum << sad;
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