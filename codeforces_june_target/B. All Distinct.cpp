/*
   **** Author: Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n;
    cin >> n ;
    long long r = n;
    vector<long long>v(n);
    set<long long>s;
    for(auto &x:v){
        cin >> x;
        s.insert(x);
    }
    // sort(v.begin() , v.end());
    // long long z = unique(v.begin() , v.end()) - v.begin();
    // cout << z << "\n";
    map<long long , long long>cnt;
    for(long long i = 0 ; i < n ; i++){
        cnt[v[i]]++;
    }
    v.assign(s.begin() , s.end());
    for(long long i = 0 ; i < v.size(); i++){
        n -= cnt[v[i]] - 1;
    }
    if((r - n) % 2){
        n--;
    }
    cout << n << "\n";
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