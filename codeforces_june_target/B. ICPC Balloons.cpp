/*
   **** Author: Md. Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
void solve()
{
    long long n ;
    cin >> n;
    string s;
    cin >> s;
    map<char , long long>mp;
    set<char>ss;
    for(long long i = 0 ; i < n ; i++){
        mp[s[i]]++;
        ss.insert(s[i]);
    }
    s.assign(ss.begin() , ss.end());
    long long ans = 0;
    for(long long i = 0 ; i < s.size() ; i++){
        if(mp[s[i]] > 1){
            ans += mp[s[i]] -1;
        }
    }
    cout << ans + ss.size() * 2 << sad;
}
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}