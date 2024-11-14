/*
   **** Author: Md. Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
void solve()
{
    long long n , l , r;
    cin >> n >> l >> r;
    long long mx = INT_MIN;
    vector<long long> v;
    for(long long i = 1 ; i <= n; i++){
        if(l % i == 0){
            v.push_back(l);
        }
        else{
            v.push_back(((l / i + 1) * i));
        }
    }
    for(auto &x:v) mx = max(x , mx);
    if(mx > r){
    //cout << mx << " " ;
        cout << "NO" << sad;
    }
    else{
        cout << "YES" << sad;
        for(long long i = 0; i < n ; i++){
            cout << v[i] << " ";
        }
        cout << sad;
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