/*
   **** Author: Md. Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
void solve()
{
    long long  x , y , n , r;
    cin >> x >> y >> n >> r;
    if(r < x*n){
        cout << -1 << sad;
        return;
    }
    if(r / y >= n ){
        cout << 0 << " " << n << sad;
        return;
    }
    long long np = (r - x * n) / (y - x);
    cout << n - np << " " << np << sad;
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