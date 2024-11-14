/*
   **** Author: Md. Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
void solve()
{
    long long n ;
    cin >> n;
    long long cnt = 0;
    vector<long long>v(n);
    long long zero = 0;
    for(auto &x : v) {
        cin >> x;
        if(x == 0){
            zero++;
        }
    }
    if(zero == n){
        cout << 0 << sad;
        return;
    }
    if(v[0] != 0){
        cnt++;
    }
    for(long long i = 0; i < n - 1 ; i++){
        if(v[i] == 0 && v[i+1] != 0 ){
            cnt++;
        }
    }    
    long long ans = 2;
    cout << min(cnt , ans) << sad;
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