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
    long long  n;
    cin >> n ;
    vector<long long>v(2 * n );
    for(auto &x:v) cin >> x;
    map<long long , long long> mp;
    for(auto &x:v){
        if(mp[x]!=1){
            mp[x] = 1;
            cout << x << " " ;
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