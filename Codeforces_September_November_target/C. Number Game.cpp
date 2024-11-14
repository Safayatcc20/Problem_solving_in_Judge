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
    vector<long long> v(n);
    set<long long> s;
    map<long long, long long> mp;
    for (auto &x : v)
    {
        cin >> x;
        s.insert(x);
        mp[x]++;
    }
    // sort(all(v));
    if (n == 1)
    {
        cout << 1 << sad;
        return;
    }
    sort(all(v));
    long long ans = 0, k = n;
    for (long long i = 1; 2 * i - 1 <= n; i++)
    {
        bool flag = true;
        long long pos = 1;
        for (long long j = i - 1; j < 2 * i - 1; j++)
        {
            if (v[j] > pos)
            {
                // cout << j << sad;
                flag = false;
                break;
            }
            pos++;
        }
        if (flag)
        {
            ans = i;
        }
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