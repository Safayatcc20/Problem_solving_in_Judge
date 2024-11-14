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
    long long n;
    cin >> n;
    n /= 2;
    vector<long long>v, vv;
    while(n--){
        long long a , b;
        cin >> a >> b;
        v.push_back(a);
        vv.push_back(b);
    }
    sort(all(v));
    sort(all(vv));
    for(auto &x:v) cout << x << " ";
    for(long long i = vv.size()-1; i >= 0; i--){
        cout << vv[i] << " ";
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