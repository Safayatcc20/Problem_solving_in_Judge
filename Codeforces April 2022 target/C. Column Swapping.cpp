//unsolve
#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n , m , x;
    cin >>  n >> m;
    vector<vector<long long > >v;
    long long a[n][m];
    for(long long i = 0; i < n; i++){
            vector<long long > row;
        for(long long j = 0 ; j < m; j++){
            cin >> x;
            row.push_back(x);
        }
        v.push_back(row);
    }
    for(long long i = 0 ; i < n; i++){
        for(lon long j = 1 ; j < m; j++){
            if(v[i][j] < v[i][j-1]){
                    ind = i , col = j;
                    break;
            }
        }
    }
    for(long long i = 0 ; i < n; i++){
        for(lon long j = 1 ; j < m; j++){
            if(v[i][j] < v[i][j-1]){
                    ind = i , col = j;
                    break;
            }
        }
    }
}
int main()
{
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}
