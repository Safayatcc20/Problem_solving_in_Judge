/*
   **** Author: Md. Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
#define end '\n' 
void solve()
{
    long long n;
    cin >> n;
    string s;
    cin >> s;
    string ans = "";
    for(long long i = 0; i < n; i++){
        if(s[i] == 'A'){
            ans += 'T';
        }
        if(s[i] == 'T'){
            ans += 'A';
        }
        if(s[i] == 'G'){
            ans += 'C';
        }
        else if(s[i] == 'C'){
            ans += 'G';
        }
    }
    cout << ans << end;
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