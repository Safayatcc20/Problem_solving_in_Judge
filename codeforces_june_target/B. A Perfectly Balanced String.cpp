/*
   **** Bismillahir Rahmanir Rahim ****
*/

#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
#define all(b) b.begin() , b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
long long t = 1;
void solve()
{
    string s;
    cin >> s;
    set<char>ss;
    for(long long i = 0; i < s.size() ; i++){
        ss.insert(s[i]);
    }
    if(ss.size() == 1){
        ha;
        return;
    }
    for(long long i = 0; i < s.size() ; i++){
        if(s[i] != s[i % ss.size()]){
            na;
            return;
        }
    }
    ha;
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