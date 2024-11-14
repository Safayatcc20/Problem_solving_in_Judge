#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define no "NO"
#define yes "YES"
void solve()
{
    int n;
    cin >> n;
    map<string, long long> mp;
    while (n--)
    {
        string s;
        cin >> s;
        string t;
        char ch = 'A';
        //cout << ch-'A'+'1';
        map<char, char> mmp;
        for (int i = 0; i < s.size(); i++)
        {
            if (mmp[s[i]]>= 'A' and mmp[s[i]] <= 'Z')
            {
                t.push_back(mmp[s[i]]);
            }
            else
            {
                mmp[s[i]] = ch;
                t.push_back(ch);
                //t += ch;
                if(ch == 'Z') continue;
                ch++;
            }
        }
        // cout <<t << sad;
        mp[t]++;
    }
    long long ans = 0;
    for (auto &x : mp)
    {
        ans += x.second * (x.second - 1) / 2;
    }
    cout << ans << sad;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long t = 1;
    //cin >> t;
    long long i = 1;
    while (t--)
    {
        //cout << "Case "<<i<<": ";
        i++;
        solve();
    }
}