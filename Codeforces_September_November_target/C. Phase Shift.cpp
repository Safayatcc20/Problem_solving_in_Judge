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
    map<char, char> mp;
    char ch = 'a';
    vector<long long> v(27);
    vector<char> vv;
    long long cnt = 0;
    for (long long i = 0; i < n; i++)
    {
        if (v[s[i] - 'a' + 1] != 1)
        {
            if (ch == s[i - 1] || s[i] == ch)
            {
                vv.push_back(ch);
                cnt++;
                ch++;
                if (ch == 'z')
                {
                    mp[s[i]] = 'a';
                }
                mp[s[i]] = ch;
                cout << ch << " ";
            }
            else
            {
                if (ch == 'z')
                {
                    mp[s[i]] = 'a';
                }
                cnt++;
                mp[s[i]] = ch;
                ch++;
                cout << ch << " ";
                v[s[i] - 'a' + 1] = 1;
            }
        }
    }
    long long j = 0;
    for (long long i = 0; i < n; i++)
    {
        /* if (mp[s[i]] < 'a' || mp[s[i]] > 'z')
        {
            cout << vv[j];
            j++;
            continue;
        } */
        cout << mp[s[i]];
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