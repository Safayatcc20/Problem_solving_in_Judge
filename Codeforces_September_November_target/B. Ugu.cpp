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
    string s;
    cin >> s;
    if (n == 1)
    {
        cout << 0 << sad;
        return;
    }
    if (n == 2)
    {
        if (s[0] == '1' and s[1] == '0')
        {
            cout << 1 << sad;
        }
        else
        {
            cout << 0 << sad;
        }
        return;
    }
    map<long long, long long> mp;
    set<char> chk;
    for (long long i = 0; i < n; i++)
    {
        chk.insert(s[i]);
        mp[s[i] - '0']++;
    }
    if (chk.size() == 1)
    {
        cout << 0 << sad;
        return;
    }
    long long adj = 0;
    for (long long i = 0; i < n; i++)
    {
        if (s[i] == '1' and s[i + 1] == '1')
        {
            i++;
            adj++;
        }
    }
    if (adj)
    {
        cout << adj + mp[1] - 2 * adj << sad;
    }
    else
    {
        if (s[0] == '1' and s[n - 1] == '1')
        {
            cout << mp[1] << sad;
        }
        else if (s[0] == '1' and s[n - 1] == '0')
        {
            cout << mp[1] + 1 << sad;
        }
        else if (s[0] == '0' and s[n - 1] == '0')
        {
            cout << mp[1] + 2 << sad;
        }
        else
        {
            cout << mp[1] << sad;
        }
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