/*
   **** Author: Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n = 8;
    char a[8][8];
    for(long long i = 0; i < n ; i++){
        for(long long j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    long long r ,c ;
    for(long long i = 0; i < n ; i++){
        for(long long j = 0; j < n; j++){
            if(a[i][j] == '#' && a[i-1][j-1] == '#' && a[i-1][j+1] == '#' && a[i+1][j-1] == '#' && a[i+1][j+1]=='#'){
                r = i, c = j;
            }
        }
    }
    cout << r + 1 << " " << c + 1 << "\n";
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