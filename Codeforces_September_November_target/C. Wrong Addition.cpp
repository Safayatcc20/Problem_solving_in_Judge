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
    string s, t;
    cin >> s >> t;
    vector<long long> vs, vt, ans;
    for (long i = 0; i < s.size(); i++)
    {
        vs.push_back(s[i] - '0');
    }
    for (long i = 0; i < t.size(); i++)
    {
        vt.push_back(t[i] - '0');
    }
    /* for (auto &x : vs)
    {
        cout << x << " ";
    }
    cout << sad;
    for (auto &x : vt)
    {
        cout << x << " ";
    }
    cout << sad; */
    long long j = vs.size() - 1;
    for (long long i = vt.size() - 1; i >= 0; i--)
    {
        if (j < 0)
        {
            ans.push_back(vt[i]);
            break;
        }
        else if (vt[i] >= vs[j])
        {
            long long cal = vt[i] - vs[j];
            // cout << cal << sad;
            ans.push_back(cal);
            j--;
        }
        else
        {
            long long make_no = vt[i - 1] * 10 + vt[i];
            long long cal = make_no - vs[j];
            // cout << cal << sad;
            ans.push_back(cal);
            i--;
            j--;
        }
    }
    // cout << ans.size() << " " << vs.size() << sad;
    long long result = 0;
    for (long long i = ans.size() - 1; i >= 0; i--)
    {
        if (i == ans.size() - 1 && ans[i] == 0)
        {
            continue;
        }
        result = result * 10 + ans[i];
        // cout << ans[i];
    }
    vector<long long> new_ans;
    j = 0;
    long long cnt = 0;
    // if(vs.size() != ans.size())
    for (long long i = vs.size() - 1; i >= 0; i--)
    {
        if (j > ans.size() - 1)
        {
            new_ans.push_back(vs[i]);
        }
        else if (ans[j] > 9)
        {
            if (cnt == 0)
            {
                cnt++;
                new_ans.push_back(vs[i] + ans[j] % 10);
                if (i == 0)
                {
                    new_ans.push_back(ans[j] / 10);
                }
            }
            else
            {
                new_ans.push_back(vs[i] + ans[j] / 10);
                j++;
                cnt = 0;
            }
        }
        else
        {
            new_ans.push_back(vs[i] + ans[j]);
            j++;
            if (i == 0 && j < ans.size())
            {
                new_ans.push_back(ans[j]);
            }
        }
    }
    string compare = "";
    for (long long i = new_ans.size() - 1; i >= 0; i--)
    {
        // cout << new_ans[i] << sad;
        if (new_ans[i] > 9)
        {
            compare += (new_ans[i] / 10) + '0';
            compare += (new_ans[i] % 10) + '0';
        }
        else
        {
            compare += new_ans[i] + '0';
        }
    }
    // cout << compare << sad;
    if (compare.size() == t.size())
    {
        if (compare == t)
        {
            cout << result << sad;
        }
        else
        {
            cout << -1 << sad;
        }
    }
    else
    {
        reverse(all(compare));
        long long zero = t.size() - compare.size();
        for (long long i = 0; i < zero; i++)
        {
            compare += '0';
        }
        if (compare == t)
        {
            cout << result << sad;
        }
        else
        {
            cout << -1 << sad;
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