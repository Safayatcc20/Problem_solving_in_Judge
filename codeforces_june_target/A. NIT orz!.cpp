/*
   **** Author: Md. Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
#define end '\n' 
void solve()
{
    long long n , z;
    cin >> n >> z;
    vector<long long>v(n);
    for(auto &x: v) cin >> x;
    long long mx = INT_MIN;
    for(auto &x:v){
        mx = max(x | z , mx);
    }
    cout << mx << end;
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