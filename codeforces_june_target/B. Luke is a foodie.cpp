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
    long long n , x;
    cin >> n >> x;
    vector<long long>v(n);
    for(auto &x:v) cin >> x;
    long long mns = v[0] - x , eat = 0;
    long long mxs = v[0] + x;
    for(long long i = 1; i < n ; i++){
        if(v[i]  > mxs + x){
            eat++;
            mns = v[i] - x;
            mxs = v[i]+x;
        }
        else if(v[i] < mns - x){
            eat++;
            mns = v[i] - x;
            mxs = v[i] + x;
        }
        else{
            if(v[i] > mns + x){
                mns = v[i] - x;
            }
            if(v[i] < mxs - x){
                mxs = v[i] + x;
            }
        }
    }
    cout << eat << sad;
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