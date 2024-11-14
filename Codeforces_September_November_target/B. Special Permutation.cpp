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
    long long n, a, b;
    cin >> n >> a >> b;
    long long chk = (n - b), cnt = 0;
    if (chk == n / 2 and (a - b) > 1)
    {
        cout << -1 << sad;
        return;
    }
    vector<long long> ft, sec;
    map<long long, long long> mp;
    ft.push_back(a);
    mp[a] = 1;
    for (long long i = b + 1; i <= n; i++)
    {
        if (mp[i] != 1)
        {
            mp[i] = 1;
            ft.push_back(i);
        }
    }
    if (ft.size() > n / 2)
    {
        cout << -1 << sad;
        return;
    }
    if (ft.size() < n / 2)
    {
        for (long long i = a + 1; i < b; i++)
        {
            if (mp[i] != 1 and ft.size() <= n / 2)
            {
                mp[i] = 1;
                ft.push_back(i);
            }
            if (ft.size() == n / 2)
                break;
        }
        if (ft.size() > n / 2 || ft.size() < n / 2)
        {
            cout << -1 << sad;
            return;
        }
    }
    sec.push_back(b);
    for (long long i = 1; i < b; i++)
    {
        if (mp[i] != 1)
        {
            mp[i] = 1;
            sec.push_back(i);
        }
    }
    for (long long i = 0; i < ft.size(); i++)
    {
        cout << ft[i] << " ";
    }
    for (long long i = 0; i < sec.size(); i++)
    {
        cout << sec[i] << " ";
    }
    cout << sad;
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