/*
   **** Bismillahir Rahmanir Rahim ****
*/

#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
#define all(b) b.begin() , b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
long long t = 1;
void solve()
{
    long long n , k , cnt = 0;
    cin  >> n >> k;
    map<long long , long long> mp;
    vector<long long>v(n);
    for(auto &x:v) cin >> x;
    for(long long i = 0; i < k; i++){
        mp[v[i]]++;
    }
    sort(all(v));
    for(long long i = 0; i <  k ; i++){
        
        if(mp[v[i]] != 1){
            cnt++;
        }
    }
    cout << cnt << sad;
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