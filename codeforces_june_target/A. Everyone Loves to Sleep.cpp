/*
   **** Bismillahir Rahmanir Rahim ****
   **** Author: Md. Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
#define all(b) b.begin() , b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
void solve()
{
    long long n , h , m;
    cin >> n >> h >> m;
    long long hm = h * 60 + m;
    vector<pair<long long , long long>>v(n);
    for(long long i = 0; i < n ; i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin() , v.end());
    long long ans = INT_MAX;
    v.push_back({v[0].first + 24 , v[0].second});
   // cout << (v[0].first + 24)*60 + v[0].second << sad;
    for(long long i = 0; i < v.size(); i++){
        if(v[i].first > h || (v[i].first == h && m <= v[i].second)){
            ans = min(ans  , abs(((v[i].first) * 60 + v[i].second) - (hm)));
            
        }
    }
    cout << ans / 60 << " " << ans % 60 <<sad; 
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