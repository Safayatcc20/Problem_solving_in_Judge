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
    map<long long, long long> mp;
    for (long long i = 0; i < n; i++)
    {
        if (s[i] == 'Q')
        {
            bool flag = false;
            for (long long j = i + 1; j < n; j++)
            {
                if (s[j] == 'A' && mp[j] != 1)
                {
                    mp[j] = 1;
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                cout << "No" << sad;
                return;
            }
        }
    }
    cout << "Yes" << sad;
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