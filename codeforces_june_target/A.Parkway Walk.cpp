/*
   **** Author: Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long a, b;
    cin >> a >> b;
    long long sum = 0;
    vector<long long> v(a);
    for(auto &x:v){
        cin >> x;
        sum += x;
    }
    if(sum > b){
        cout << sum - b << "\n";
    }
    else{
        cout << 0 << "\n";
    }
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