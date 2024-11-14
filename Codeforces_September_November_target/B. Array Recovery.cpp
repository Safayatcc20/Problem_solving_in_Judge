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
    for (auto &x : v)
        cin >> x;
    bool flag = true;
    vector<long long> a(n);
    a[0] = v[0];
    long long j = 1;
    for (long long i = 1; i < n; i++)
    {
        long long chk = v[i] + a[j - 1];
        long long chkk = -v[i] + a[j - 1];
        // cout << chk << " " << chkk << sad;
        if (chk >= 0 && chkk >= 0 && chkk != chk)
        {
            flag = false;
            break;
        }
        else
        {
            a[j] = v[i] + a[j - 1];
            j++;
        }
    }
    if (flag)
    {
        for (long long i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
    }
    else
    {
        cout << -1;
    }
    cout << sad;
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