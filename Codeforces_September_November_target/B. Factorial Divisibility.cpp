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
unsigned long long fact(unsigned long long n)
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
    long long n, x;
    cin >> n >> x;
    vector<long long> v(n);
    map<long long, long long> mp;
    for (auto &x : v)
    {
        cin >> x;
        mp[x]++;
    }
    bool flag = true;
    for (long long i = 1; i < x; i++)
    {
        if (mp[i] % (i + 1) == 0)
        {
            mp[i + 1] += (mp[i] / (i + 1));
        }
        else
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << "Yes" << sad;
    }
    else
    {
        cout << "No" << sad;
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