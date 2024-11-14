/*
   **** Author: Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long a;
    cin >>  a;
    vector<long long>v(3);
    for(long long i = 0 ; i < 3; i++){
        cin >> v[i];
    }
    long long cnt = 0;
    for(long long i = 0 ; i < 3 ;i++){
        if(v[i] >= a){
            cnt++;
        }
    }
    cout << cnt << "\n";
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