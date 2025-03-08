/*
 **** Bismillahir Rahmanir Rahim ****
 */

#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "Yes" << '\n'
#define na cout << "No" << '\n'
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
    long long n, m;
    cin >> n >> m;
    long long take = m;
    vector<vector<long long>> v(m);
    map<pair<long long, long long>, long long> mp;
    vector<long long> kk(m);
    set<vector<long long>> s;
    long long ind = 0;
    long long sum = 0;
    while (take--)
    {
        long long k;
        cin >> k;
        kk.push_back(k);
        vector<long long> vv(k);
        for (long long i = 0; i < k; i++)
        {
            cin >> vv[i];
        }
        pair<long long, long long> p;
        for (long long i = 0; i < k; i++)
        {
            for (long long j = i + 1; j < k; j++)
            {
                if (mp[{vv[i], vv[j]}] != 1)
                {
                    mp[{vv[i], vv[j]}] = 1;
                    sum += 1;
                }
            }
        }
    }
    if (n == 2)
    {
        if (sum == 1)
        {
            cout << "Yes" << sad;
        }
        else
        {
            na;
        }
    }
    else
    {
        long long res;
        res = (((n - 1)) * (n)) / 2;
        if (sum == res)
        {
            ha;
        }
        else
        {
            na;
        }
    }
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