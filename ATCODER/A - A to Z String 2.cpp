/*
   **** Author: Md. Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
#define end '\n' 
void solve()
{
    long long n , x;
    cin >> n >> x;
    long long ans ;
    if(x % n == 0){
        ans = x / n;
        cout << char (ans + 'A' - 1) << end;
    }
    else{
        ans = x / n ;
        cout << char(ans + 65) << end;
    }
}
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    /* long long t;
    cin >> t;
    while(t--){ */
        solve();
    //}
}