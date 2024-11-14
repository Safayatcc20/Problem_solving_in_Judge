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
long long comp(pair<long long, long long> &a, pair<long long, long long> &b)
{
    return (a.first > b.first || (a.first == b.first && a.second > b.second));
}
long long commp(pair<long long, long long> &a, pair<long long, long long> &b)
{
    return (a.first < b.first || (a.first == b.first && a.second > b.second));
}
void solve()
{
    string s;
    cin >> s;
    map<char, long long> mp;
    long long ans = 0;
    vector<pair<long long, long long>> pa;
    cout << abs(s[0] - s[s.size() - 1]) << " ";
    if (s[0] > s[s.size() - 1])
    {
        for (char i = s[0]; i >= s[s.size() - 1]; i--)
        {
            mp[i]++;
        }
        for (long long i = 1; i < s.size() - 1; i++)
        {
            if (mp.find(s[i]) != mp.end())
            {
                ans++;
                pa.push_back({s[i] - 'a' + 1, i + 1});
            }
        }
        cout << ans + 2 << sad;
        sort(all(pa), comp);
        cout << 1 << " ";
        for (long long i = 0; i < pa.size(); i++)
        {
            // cout << pa[i].first << " " << pa[i].second << sad;
            cout << pa[i].second << " ";
        }
        cout << s.size() << sad;
    }
    else
    {
        for (char i = s[0]; i <= s[s.size() - 1]; i++)
        {
            mp[i]++;
        }
        for (long long i = 1; i < s.size() - 1; i++)
        {
            if (mp.find(s[i]) != mp.end())
            {
                ans++;
                pa.push_back({s[i] - 'a' + 1, i + 1});
            }
        }
        cout << ans + 2 << sad;
        sort(all(pa), commp);
        // cout << 1 << " ";
        for (long long i = 0; i < pa.size(); i++)
        {
            cout << pa[i].first << " " << pa[i].second << sad;
            // cout << pa[i].second << " ";
        }
        cout << s.size() << sad;
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