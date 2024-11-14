/*
 **** Author: Md. Safayat Bin Nasir ****
 */

#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
void solve()
{
    long long n, c, q;
    cin >> n >> c >> q;
    vector<string> v;
    string s, ss = "";
    cin >> s;
    long long len = s.size();
    for (long long i = 0; i < c; i++)
    {
        long long l, r;
        cin >> l >> r;
        for (long long j = l - 1; j < r; j++)
        {
            ss += s[j];
        }
        v.push_back(ss);
        ss.clear();
        // cout << s;
    }
    // cout << s;
    for (long long i = 0; i < q; i++)
    {
        long long x;
        cin >> x;
        cout << v[x - 1] << sad;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}