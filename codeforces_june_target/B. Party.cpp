/*
   **** Author: Md. Safayat Bin Nasir **** 
*/

//unsolved;
#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
void solve()
{
    long long n , m;
    cin >> n  >> m;
    vector<long long> v(n);
    for(auto &x:v) cin >> x;
    if( m == 0){
        cout << 0 << sad;
        return;
    }
    long long mn = INT_MAX;
    map<long long , long long>mp1 , mp2;
    for(long long i = 0; i < m;  i++){
        long long x  , y;
        cin >> x >> y;
        mp1[v[x-1]] = 1 , mp2[v[y-1]] = 1;
    }
    //vector<pair<long long , long long>>ch;
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < n; j++){
            if(j != i){
                if(mp1[v[i]] != 1 && mp2[v[j]]!= 1){
                    long long ch = v[i] + v[j];
                    mn = min(mn , ch);
                }
            }     
        }
    }
    /*  for(long long i = 0; i < n ; i++){
        if(mp[ch[i]] != 1){
            long long sum = ch[i].first + ch[i].second;
            mn = min(mn , sum);
        }
    } */ 
    cout << mn << sad;
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