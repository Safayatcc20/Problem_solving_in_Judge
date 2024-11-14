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
    long long n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<char, long long> mp;
    set<char> ss;
    for (long long i = 0; i < s.size(); i++)
    {

        mp[s[i]]++;
    }
    vector<long long> v(26);
    for (auto &x : mp)
    {
        v[x.first - 'a'] = x.second;
        // cout << v[x.first - 'a'] << sad;
    }
    long long take = k;
    string ans = "";
    while (take--)
    {
        /* code */
        bool flag = true;
        long long j = 0;
        long long mx;
        if (n / k < 26)
        {
            mx = n / k;
        }
        else
        {
            mx = 26;
        }
        long long me = 0;
        for (int i = 0; i < mx; i++)
        {
            if (v[i] == 0)
            {
                me = i;
                flag = false;
                break;
            }
            v[i]--;
        }
        if (flag)
        {
            ans.push_back('a' + n / k);
        }
        else
        {
            ans.push_back('a' + me);
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