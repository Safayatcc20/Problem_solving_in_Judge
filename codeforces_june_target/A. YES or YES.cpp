/*
   **** Author: Md. Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
void solve()
{
    string s;
    cin >> s;
    if((tolower(s[0]) =='y' && tolower(s[1])=='e' && tolower (s[2])=='s') || s[0] =='Y' &&s[1]=='E'&&s[2]=='S'){
        cout << "YES" << sad;
    }
    else{
        cout << "NO" << sad;
    }
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