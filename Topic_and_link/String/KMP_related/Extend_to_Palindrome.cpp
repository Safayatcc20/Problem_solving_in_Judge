/*
 **** Bismillahir Rahmanir Rahim ****
 */

#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define minusone cout << "-1" << '\n'
void KMP(string s, vector<int> &lps)
{
    int n = s.size();
    int len = 0;
    int i = 1;
    lps[0] = 0;
    while (i < n)
    {
        if (s[i] == s[len])
        {
            len++, lps[i] = len, i++;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = 0, i++;
            }
            else
            {
                len = lps[len - 1];
            }
        }
    }
    // for(auto &x:lps){
    //     cout << x << " ";
    // }
    // cout << sad;
}
void solve()
{
    string s;
    while (cin >> s)
    {
        string t = s;
        reverse(all(t));
        string ns = t  + s;
        int cnt = 1;
        vector<int> lps(ns.size());
        // cout << s.size() << sad;
        KMP(ns, lps);
        /* for(auto &x:lps){
            cout << x << " ";
        } */
        // cout << sad;
        int n = s.size();
        int period = n - lps[ns.size() - 1];
        // cout  << n << "  "<< ns.size()  << " "<< lps[ns.size() - 1]<< " "<<period << sad;
        if(period > 0){
            cout << s ;
            for(int i = period-1; i >= 0;i--){
                cout << s[i];
            }
            cout << sad;
        }
        else cout << s << sad;
        
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}