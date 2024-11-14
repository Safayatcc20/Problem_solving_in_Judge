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
    vector<pair<long long, long long>> v(n);
    for (auto &x : v)
    {
        cin >> x.first >> x.second;
    }
    sort(all(v));
    bool flag = false;
    string ans = "";
    long long up = 0, right = 0;
    for (auto &x : v)
    {
        // cout << x.first << " " << x.second << endl;
        if (x.first >= right && x.second >= up)
        {

            for (long long i = right; i < x.first; i++)
            {
                ans += 'R';
            }
            right = x.first;
            for (long long i = up; i < x.second; i++)
            {
                ans += 'U';
            }
            up = x.second;
        }
        else
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        na;
    }
    else
    {
        ha;
        cout << ans << sad;
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