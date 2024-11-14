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
    vector<long long>v(n);
    for(long long i = 0; i < 3 ;i++){
        cin >> v[i];
    }
    if(v[n-1] == 0){
        cout << "NO" << sad;
    }
    else if(v[v[n-1]-1] == 0){
        cout << "NO" << sad;
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