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
    long long n , s , k;
    cin >> n >> s >> k;
    vector<long long>v(n);
    for(auto &x:v) cin >> x;
    long long sum  = s , cnt = 0;
    for(long long i = 0; i < n ; i++){
        if(v[i] == 0){
            cnt++;
            if(cnt == k){
                sum += 1;
                cnt  = 0;
            }
        }
        else{
            cnt = 0;
            sum -= v[i];
        }
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