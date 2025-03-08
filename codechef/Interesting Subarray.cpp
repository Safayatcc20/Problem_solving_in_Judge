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
    cin >> n ;
    vector<long long>v(n);
    long long mn = INT_MAX;
    for(auto &x:v) {
        cin >> x;
        if(x >= 0)
        {
            mn = min(x , mn);
        }
    }
    long long mx  = *max_element(v.begin() , v.end());
    long long mnn  = *min_element(v.begin() , v.end());
    if(mn == INT_MAX){
        cout << mx * mx << " " << mnn * mnn << sad;
    }
    else{
        if(mn < 0 && mx > 0){
            cout << mn * mx << " " << mx * mx << sad;
        }
        else{
            cout << mn * mn << " " << mx * mx << sad;
        }
    }
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