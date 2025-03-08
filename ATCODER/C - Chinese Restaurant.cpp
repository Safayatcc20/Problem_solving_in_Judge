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
    vector<long long>v(n);
    for(auto &x:v) cin >> x;
    long long cnt = 0;
    if(v[0] == 0){
        cout << n << sad;
        return;
    }
    long long ind = -1;
    for(long long i = 0; i < n; i++){
        if(v[i] == 0){
            ind = i;
            break;
        }
        cnt++;
    }
        //cout << ind << sad;
    if(ind == n -2){
        cout << n << sad;
    }
    else{
        long long ans = n - ind - 1;
        cout << ind - ans << sad;
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