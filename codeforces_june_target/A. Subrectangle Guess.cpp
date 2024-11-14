/*
   **** Author: Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n , m;
    cin  >>  n >> m;
    long long a[n][m];
    for(long long i = 0 ; i < n ; i++){
        for(long long j = 0 ; j < m; j++){
            cin >> a[i][j];
        }
    }
    long long mx = INT_MIN , r = -1 , c = -1;
    for(long long i = 0; i < n; i++){
        for(long long j  = 0 ; j < m; j++){
            if(mx < a[i][j]){
                mx = a[i][j];
                r = i;
                c = j;
            }
        }
    }
    r = max(r , n - r -1) + 1;
    c = max(c , m - c - 1) + 1;
    cout << r <<  c << "\n";
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