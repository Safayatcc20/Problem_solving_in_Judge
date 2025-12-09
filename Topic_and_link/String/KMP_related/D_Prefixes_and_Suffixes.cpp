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
        vector<int> lps(s.size());
        // cout << s.size() << sad;
        KMP(s, lps);
        /* for(auto &x:lps){
            cout << x << " ";
        } */
        // cout << sad;
        int n = s.size();
        vector<int>freq(n+1 , 0);
        for(int i = 0 ; i < n;i++) freq[lps[i]]++;
        //every prefix is also a prefix of its longer prefix
        for(int i = n -1 ;i>0 ;i--) freq[lps[i-1]] += freq[i];
        for(int i = n  ;i>=0 ;i--) freq[i]++; // Each prefix occurs at least once (itself)
        
        vector<int>ans;
        int len = n;
        while(len > 0){
            ans.push_back(len);
            len = lps[len-1];
        }
        reverse(all(ans));
        cout << ans.size() << sad;
        for(auto &x:ans) cout << x << " "<< freq[x] << endl;

        
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