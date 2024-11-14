/*
   **** Author: Md. Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
void solve()
{
    long long n , k;
    cin >> n >> k;
    if(3 * n > k){
        cout << 3 * n - k << sad;
    }
    else{
        cout << 0 << sad;
    }
}
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}