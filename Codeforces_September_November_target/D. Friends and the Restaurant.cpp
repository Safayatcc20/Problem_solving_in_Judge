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
    vector<long long> vv(n);
    for (auto &x : v)
        cin >> x;
    for (auto &x : vv)
        cin >> x;
    vector<long long> dif(n);
    for (long long i = 0; i < n; i++)
    {
        dif[i] = vv[i] - v[i];
    }
    long long cnt = 0;
    sort(all(dif));
    reverse(all(dif));
    long long chk = n - 1;
    for (long long i = 0; i < n; i++)
    {
        while (dif[i] + dif[chk] < 0)
        {
            chk--;
        }
        if (chk <= i)
        {
            break;
        }
        cnt++;
        chk--;
    }
    cout << cnt << sad;
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