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
    long long n, x;
    cin >> n >> x;
    long long sum = 0, ans = 0;
    vector<long long> v(n), vv;
    for (auto &x : v)
        cin >> x;
    sort(all(v));
    for (auto &k : v)
    {
        sum += (k / x);
    }
    for (long long i = 0; i < n; i++)
    {
        v[i] = v[i] % x;
    }
    sort(all(v));
    long long ind = 0, j = n - 1;
    for (long long i = 0; i < n; i++)
    {
        if (v[i] != 0)
        {
            ind = i;
            break;
        }
    }
    while (ind < j)
    {
        if (v[ind] + v[j] >= x)
        {
            sum++;
            j--;
            ind++;
        }
        else
        {
            ind++;
        }
    }
    cout << sum << sad;
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