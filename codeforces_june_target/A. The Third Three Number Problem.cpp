/*
   **** Author: Md. Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
void solve()
{
    long long n;
    cin >> n;
    if(n % 2 == 0){
        int a = 0 , b =  n / 2 , c = 0;
        //cout << (a ^ b) + (b ^ c ) + (a ^ c) << sad;
        cout << a << " " << b << " " << c << sad;
        return ;
    }
    cout << -1 << sad;
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