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
    cin >> n ;
    vector<long long> v(n);
    for(auto &x:v) cin >> x;
    vector<long long>vv(10);
    for(auto &x:vv) cin >> x;
    long long mn = INT_MAX;
    long long mini = INT_MAX;
    long long mx = INT_MIN;
    long long mix = INT_MIN;
    for(auto &x:v) mn = min(mn , x);
    for(auto &x:v) mx = max(mx , x);
    for(auto &x:vv) mini = min(mini , x);
    for(auto &x:v) mix = max(mix , x);
    if(mini > mn){
      cout << mn << sad; 
      return;
    }
    cout << mx << sad;
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