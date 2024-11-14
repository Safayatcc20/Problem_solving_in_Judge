/*
   **** Author: Md. Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
void solve()
{
    long long n , x;
    cin >> n >> x;
    vector<long long>v(n*2);
    for(auto &x:v) cin >> x;
    sort(v.begin() , v.end());
    long long flag = 0;
    for(long long i = 0; i < n; i++){
        if(v[n+i] - v[i] < x){
            flag = 1;
            break;
        }
    }
    if(flag ){
        cout << "NO" <<sad;
    }
    else{
        cout << "YES" << sad;
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