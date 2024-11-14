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
void solve()
{
    long long n;
    cin >> n;
    vector<long long> v(n);
    long long sum = 0, sum1 = 0;
    for (auto &x : v)
    {
        cin >> x;
        if (x > 6)
        {
            if (x % 6)
            {
                sum += x % 6;
            }
        }
        else
        {
            sum1 = (x % 6);
        }
    }
    if (sum1)
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