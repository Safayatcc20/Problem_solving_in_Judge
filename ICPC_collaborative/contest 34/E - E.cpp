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
long long gcd(long long x , long long y){
  if(y == 0) return x;
  return gcd(y ,  x % y);
}
void solve()
{
    long long n , k;
    cin >> n >> k;
    vector<long long>v(n);
    for(auto &x:v) cin >> x;
    long long res;
    res = gcd(v[0] , v[1]);
   // cout << res << sad;
    
    for(long long i = 2; i < n ; i++){
      //  cout << v[2] << " ";
        res = gcd(v[i] , res);
       // cout << res << sad;
    }
    long long mx = INT_MIN;
    for(long long i = 0 ; i < n ; i++){
        mx=max(v[i] , mx);
    }
    //cout << mx << sad;
    if(k % res || k > mx){
        cout << "IMPOSSIBLE" << sad;
    }
    else{
        cout << "POSSIBLE" << sad;

    }
}
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //long long t;
    //cin >> t;
    while(t--){
        solve();
    }
}