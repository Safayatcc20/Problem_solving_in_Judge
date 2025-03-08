/*
   **** Author: Md. Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
#define end '\n' 
void solve()
{
    long long n , k , q;
    cin >> n >> k >> q;
    vector<long long>v(k+1);
    for(long long i = 0; i < k ; i++){
        cin >> v[i];
    }
    v[k] = 0;
    for(long long i = 0; i < q;i++){
        long long x;
        cin >> x;
        if(v[x-1] < n && v[x-1] + 1 != v[x - 1+ 1]){
            v[x-1] = v[x-1] + 1;
        }
    }
    for(long long i = 0; i < k ; i++){
        cout << v[i] << " ";
    }
}
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    /* long long t;
    cin >> t;
    while(t--){ */
        solve();
   //}
}