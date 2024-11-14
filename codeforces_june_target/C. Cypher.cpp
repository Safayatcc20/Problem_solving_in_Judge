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
    vector<long long>v(n);
    for(auto &x:v){
        cin >> x;
    }
    vector<pair<long long , string>>p;
    for(long long i = 0; i < n; i++){
        long long a ;
        cin >> a ;
        string b;
        cin >> b;
        map<char ,long long>mp;
        for(long long i = 0; i < a ; i++){
            mp[b[i]]++;
        }
        long long d = mp['D'] - mp['U'];
        if( v[i] + d < 0){
            cout << (v[i] + d) + 10 << " ";
        }
        else if(v[i] + d > 9){
            cout << (v[i] + d) - 10 << " "; 
        }
        else{
            cout << v[i] + d << " ";
        }
    }
    cout << sad;
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