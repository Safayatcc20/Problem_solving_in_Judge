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
vector<long long> prefix(10e6);
void solve()
{
    long long n;
    cin >> n;
    // long long x = upper_bound(all(prefix), n) - prefix.begin();
    // cout << x << sad;
    long long sum = 0, i = 1, cnt = 0;
    while (sum <= n)
    {
        sum += i;
        i++;
        cnt++;
    }
    cout << cnt - 1 << sad;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // long long t;
    cin >> t;
    prefix[0] = 1;
    for (long long i = 1; i < 10e6; i++)
    {
        prefix[i] = prefix[i - 1] + 1 + i;
    }
    /* for (auto &x : prefix)
        cout << x << sad; */
    while (t--)
    {
        solve();
    }
}