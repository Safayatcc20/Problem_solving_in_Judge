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
    vector<long long>a(n);
    for(auto &x:a) cin >> x;
    for(long long i = n-1; i > 0 ;i--){
        if(a[i] % a[0]){
            cout << "NO" << sad;
            return ;
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