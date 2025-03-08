/*
   **** Author: Md. Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
#define s '\n' 
void solve()
{
    long long n;
    cin >> n;
    vector<long long>v(n);
    for(auto &x:v){
        cin >> x;
    }
    map<long long , long long>hash;
    for(long long i = 0; i < n; i++){
        hash[v[i]]++;
    }
    long long mx = 0;
    for(auto i : hash){
        if(mx < i.second){
            mx = i.second;
           // cout << mx << s;
        }
    }
    cout << n - mx << s;
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