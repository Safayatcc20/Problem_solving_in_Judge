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
    set<long long>s;
    map<long long , long long>mp;
    vector<long long > v(n);
    for(auto &x:v) {
        cin >> x;
        mp[x]++;
        s.insert(x);
    }
    if(s.size() == n){
        cout << (n * (n+1)) / 2 << sad;
        return;
    }
    vector<long long>vv;
    long long sum = n, r = n;
    vv.assign(all(s));
    for(long long i = 0; i < s.size(); i++){
        //cout << r << sad;
        r = r - mp[vv[i]];
        sum += r;
    }
    cout << sum << sad;
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