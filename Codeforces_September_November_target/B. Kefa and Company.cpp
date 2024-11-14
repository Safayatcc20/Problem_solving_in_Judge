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
long long comp(pair<long long, long long> &a, pair<long long, long long> &b)
{
    return (a.first < b.first || (a.first == b.first && a.second < b.second));
}
void solve()
{
    long long n, d;
    cin >> n >> d;
    vector<pair<long long, long long>> v;
    for (long long i = 0; i < n; i++)
    {
        long long x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(all(v), comp);
    long long ans = 0, sum = 0;
    long long l = 0, r = 0;
    while ((r < n))

    {
        if (v[r].first - v[l].first < d)
        {
            ans += v[r].second;
            r++;
        }
        else
        {
            ans -= v[l].second;
            l++;
        }
        sum = max(sum, ans);
    }
    cout << sum << sad;
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