/*
 **** Bismillahir Rahmanir Rahim ****
 */

#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin() + 1, b.end()
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
    long long n, k;
    cin >> n >> k;
    vector<long long> s(n + 1, 0), a(n + 1);
    for (long long i = n - k + 1; i <= n; i++)
    {
        cin >> s[i];
    }
    long long j = 1;
    bool flag = true;
    if (n == 1 || k == 1)
    {
        cout << "Yes" << sad;
        return;
    }
    for (long long i = n; i >= n - k + 2; i--)
    {
        a[i] = s[i] - s[i - 1];
    }
    for (long long i = n - k + 2; i < n; i++)
    {
        if (a[i] > a[i + 1])
        {
            flag = false;
            break;
        }
    }
    if (!flag)
    {
        cout << "No" << sad;
    }
    else
    {
        for (long long i = n - k + 1; i > 1; i--)
        {
            a[i] = a[i + 1];
            s[i - 1] = s[i] - a[i];
        }
        a[1] = s[1];
        for (long long i = 1; i < n; i++)
        {
            if (a[i] > a[i + 1])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << "Yes" << sad;
        }
        else
        {
            cout << "No" << sad;
        }
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