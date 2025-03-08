/*
   **** Author: Md. Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
#define end '\n' 
void solve()
{
    long long p;
    cin >> p;
    if(p < 11){
        cout << p << end;
    }
    else if(p >= 100){
        long long ans = p / 100;
        p %= 100;
        if(ans + p < 11){
            cout << ans + p << end; 
        }
        else{
            cout << - 1 << end;
        }
    }
    else{
        cout << -1 << end;
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