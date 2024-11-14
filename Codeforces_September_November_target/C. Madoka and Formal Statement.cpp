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
    vector<long long>v(n),vv(n);
    for(auto &x : v) cin >> x;
    for(auto &x : vv) cin >> x;
    bool flag = false ;
    for(long long i = 0 ; i < n; i++) {
        if(v[i] > vv[i]) {
            flag = true;
            cout << i << sad;
            break ;
        }
        else if(i == n - 1 and vv[i] > vv[0]+1 and v[i] < vv[i]){
            flag = true;
            cout << i << "do " << sad;
            break;
        }
        else if(v[i] < vv[i] && vv[(i+1)] + 1 < vv[i] and i != n-1) {
            flag = true;
            cout << i << "me";
            break ;
        }
    }
    if(flag) {
        cout << "NO" <<sad;
    }
    else {
        cout << "YES" << sad;
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