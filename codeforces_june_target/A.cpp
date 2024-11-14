/*
   **** Author: Md. Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
void solve()
{
    long long n , m;
    cin >> n >> m;
    vector<long long>v(n),l(n), r(n) ,lp(n) , rp(n);
    for(auto &x:v) cin >> x;
    for(long long i = 1; i < n ; i++){
        if(v[i-1] - v[i] > 0){
            l[i] = v[i-1] - v[i];
        }
        else{
            l[i] = 0;
        }
    }
    for(long long i = n - 1; i > 0 ; i--){
        if(v[i] > v[i-1]){
            r[i] = v[i] - v[i-1];
        }
        else{
            r[i] = 0;
        }
    }
    lp[0] = 0;
    for(long long i = 1; i < n ; i++){
        lp[i] = l[i] + lp[i-1];
    }
    rp[0] = 0;
    for(long long i = 1; i < n ; i++){
        rp[i] = r[i] + rp[i-1];
    }
   /*  for(long long i = 0; i < n ; i++){
        cout << lp[i] << " ";
    }
    cout << sad; */
    /* for(long long i = 0; i < n ; i++){
        cout << rp[i] << " ";
    }
    cout << sad; */
    while(m--){
        long long x , y;
        cin >> x >> y;
        if(x < y){
            cout << lp[y-1] - lp[x-1] << sad; 
        }
        else{
            cout << rp[x-1] - rp[y-1] << sad;
        }
    }
}
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t = 1;
   // cin >> t;
    while(t--){
        solve();
    }
}