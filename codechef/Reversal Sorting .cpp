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
    vector<long long> v(n);
    for(auto &x: v){
        cin >> x;
    }
    for(long long i = 0; i < n-1; i++){
        if(v[i] > v[i+1]){
            if(v[i] + v[i+1] > x){
                cout << "NO" << end;
                return;
            }
            else{
                swap(v[i] , v[i+1]);
            }
        }
    }
    cout << "YES" << end;
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