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
    long long n, q;
    cin >> n >> q;
    vector<long long> v(n);
    map<long long, long long> mp;
    deque<long long> d(n);
    long long mx = INT_MIN;
    for (auto &x : v)
    {
        cin >> x;
        d.push_back(x);
    }
    for (long long i = 1;; i++)
    {
        long long ft = d.front();
        d.pop_front();
        long long sec = d.front();
        d.pop_front();
        if (ft == n || sec == n)
        {
            mp[n]++;
            break;
        }
        else
        {
            mp[max(ft, sec)]++;
            cout << mp[ft] << sad;
            d.push_front(max(ft, sec));
        }
    }
    while (q--)
    {
        long long i, k;
        cin >> i >> k;
        i--;
        // cout << i << k << sad;
        if (i < 2)
        {
            if (v[i] == n)
            {
                cout << k << sad;
            }
            else
            {
                cout << min(k, mp[v[i]]) << sad;
            }
            return;
        }
        if (v[i] == n)
        {
            k -= i - 1;
            if (k < 0)
            {
                cout << 0 << sad;
            }
            else
            {
                cout << k << sad;
            }
        }
        else
        {
            k -= i - 1;
            if (k < 0)
            {
                cout << 0 << sad;
            }
            else
            {
                cout << min(k, mp[v[i]]) << sad;
            }
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