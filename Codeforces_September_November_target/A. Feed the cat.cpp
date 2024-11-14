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
    double hh, mm;
    cin >> hh >> mm;
    double h, d, c, n;
    cin >> h >> d >> c >> n;
    double ans = 0, ans2 = 0;
    double take = ceil(h / n);
    ans = take * c;
    long long difference_discount_time = (20 * 60) - hh * 60 - mm;
    if (difference_discount_time <= 0)
    {
        difference_discount_time = 0;
        ans -= ans * (0.2);
    }
    h += (difference_discount_time * d);
    take = ceil(h / n);
    c = (c - (c * 0.2));
    ans2 = c * take;
    cout << fixed << setprecision(4) << min(ans, ans2) << sad;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // cin >> t;
    while (t--)
    {
        solve();
    }
}