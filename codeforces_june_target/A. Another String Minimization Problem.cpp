/*
   **** Author: Md. Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
void solve()
{
    long long n , m;
    cin >> n >> m;
    string s , t;
    vector<long long>v(n);
    for(auto &x:v) cin >> x;
    for(long long i = 0; i < m; i++){
        s += 'B';
    }
    for(long long i = 0; i < n  ; i++){
        if(s[min(v[i] -1, m-v[i])] != 'A'){
            s[min(v[i]-1 , m-v[i])] = 'A';
        }
        else{
            s[max(v[i] -1, m-v[i])] = 'A';
        }
    }
    cout << s << sad;
    
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