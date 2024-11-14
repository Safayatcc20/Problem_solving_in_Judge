/*
   **** Author: Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n , m;
    cin >> n >> m;
    long long sum = 0;
    for(long long i = 1; i <= m; i++){
        sum += i;
    }
    for(long long i = 2;  i <= n; i++){
        sum += i * m;
    }
    cout << sum << "\n";
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