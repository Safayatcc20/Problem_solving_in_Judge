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
long long get(string s)
{
    long long a = count(all(s), '0');
    long long b = count(all(s), '1');
    if (a == b)
        return 0;
    return min(a, b);
}
void solve()
{
    string s;
    cin >> s;
    string a, b;
    for (long long i = 0; i < s.size(); i++)
    {
        if (i != 0)
            a += s[i];
        if (i != s.size() - 1)
            b += s[i];
    }
    cout << max({get(s), get(a), get(b)}) << sad;
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