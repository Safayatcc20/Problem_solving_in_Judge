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
long long ncr(int n, int r)
{
    int cnt = 0, ans = 1;
    for (int i = n; cnt < r; i--)
    {
        ans *= i;
        cnt++;
    }
    return ans / 2;
}
void solve()
{
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (auto x : v)
        cin >> x;
    n = 10 - n;
    cout << 6 * ncr(n, 2) << sad;
    // cout << 6 * fact(n) / (fact(n - 2) * 2) << sad;//same
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