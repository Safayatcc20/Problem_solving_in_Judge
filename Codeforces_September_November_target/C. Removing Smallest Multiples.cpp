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
    string s;
    cin >> s;
    long long cnt = 0;
    vector<long long> v;
    for (long long i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            cnt++;
            v.push_back(i + 1);
        }
    }
    if (cnt == n)
    {
        cout << n << sad;
        return;
    }
    vector<long long> vv(n + 1, 0);
    // cout << vv[v[0]] << sad;
    long long ans = 0;
    for (long long i = 0; i < v.size(); i++)
    {
        long long test = 1;
        while (binary_search(all(v), test * v[i]))
        {
            if (vv[test * v[i]] == 0)
            {
                ans += v[i];
            }
            vv[test * v[i]] = 1;
            test++;
        }
    }
    cout << ans << sad;
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