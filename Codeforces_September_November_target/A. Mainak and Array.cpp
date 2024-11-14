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
  return gcd(y , x % y);
}
long long lcm(long long x , long long y){
  return (( x * y) /gcd(x , y));
}
void solve()
{
    long long n ;
    cin >> n;
    long long mx = INT_MIN , mn = INT_MAX;
    vector<long long>v(n);
    for(auto &x:v) {
        cin >> x;
    }
    if(n == 1){
        cout << 0 << sad;
        return;
    }
    for(long long i = 0; i < n - 1; i++){
        mn = min(mn , v[i]);
    }
    for(long long i = 1; i < n; i++){
        mx = max(mx , v[i]);
    }
    long long dis = INT_MIN;
    for(long long i = 1; i < n; i++){
        dis = max(dis , v[i-1] - v[i]);
    }
    cout << max({v[n-1] - mn  , mx - v[0] , dis}) << sad;
}
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //long long t;
    cin >> t;
    while(t--){
        solve();
    }
}