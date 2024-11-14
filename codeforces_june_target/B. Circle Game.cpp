/*
   **** Author: Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n ;
    cin >> n;
    vector<long long>v(n);
    for(auto &x:v){
        cin >> x;
    }
    if( n % 2){
        cout << "Mike" << "\n";
    }
    else{
        long long a = INT_MAX, b = INT_MAX, c , d;
        for(long long i = 0; i < n; i++){
            a = min(a , v[i]);
        }
        for(long long i = 0; i < n; i++){
            if(v[i] == a){
                b = i;
                break;
            }
        }
        if(b % 2){
            cout << "Mike";
        }
        else{
            cout << "Joe";
        }
        cout << "\n";
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