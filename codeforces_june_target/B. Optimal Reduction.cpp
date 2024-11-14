/*
   **** Bismillahir Rahmanir Rahim ****
   **** Author: Md. Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
#define all(b) b.begin() , b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
void solve()
{
    long long n;
    cin  >> n;
    vector<long long > v(n)  , vv(n);
    for(auto &x : v) cin >> x;
    vv.assign(v.begin() , v.end());
    sort(vv.begin() , vv.end());
    long long l = 0  , r = n - 1 , check  = 0;
    bool flag = true;
    while(l < r){
        if(v[l] == vv[check] ){
            l++ , check++;
        }
        else if (v[r] == vv[check]){
            r-- , check++;
        }
        else{
            cout << "NO" << sad;
            return;
        }
    }
    cout << "YES" << sad;
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