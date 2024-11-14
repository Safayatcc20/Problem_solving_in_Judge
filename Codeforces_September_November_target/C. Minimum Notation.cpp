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
    string s;
    cin >> s;
    if (is_sorted(all(s)))
    {
        cout << s << sad;
        return;
    }
    for (long long i = s.size() - 1; i > 0; i--)
    {
        if (s[i] < s[i - 1])
        {
            if (s[i - 1] < '9')
            {
                s[i - 1] = min(s[i - 1] - '0' + 1, 9) + 48;
            }
            swap(s[i], s[i - 1]);
        }
    }
    sort(all(s));
    cout << s << sad;
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