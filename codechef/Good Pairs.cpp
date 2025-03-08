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
    set<long long>s;
    vector<long long> v;
    map< long long , long  long > mp;
    for(long long i = 0; i < n ; i++){
        long long x;
        cin >> x;
        v.push_back(x);
        mp[x]++;
        s.insert(x);
    }
    v.assign(all(s));
    long long cnt = 0 , ans = 0;
    for(auto &x : v){
        if(mp[x] > 1){
            ans += (mp[x] * (mp[x]-1) )/ 2;
        }
    }
    cout << ans << sad;
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