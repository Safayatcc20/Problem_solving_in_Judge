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
    long long n , m;
    cin >> n >> m;
    long long a[n+5][m+5], c[m+5] = {0} , r[n] = {0};
    for(long long i = 0; i < n ; i++){
        for(long long j = 0; j < m ; j++){
            cin >> a[i][j];
        }
    }
    for(long long i = 0; i < n ; i++){
        for(long long j = 0; j < m ; j++){
            r[i] = r[i] + a[i][j];
        }
    }
    for(long long i = 0; i < n ; i++){
        for(long long j = 0; j < m ; j++){
            c[j] = c[j] + a[i][j];
        }
    }
    long long sum = 0 , rw  = 0;
    for(long long i = 0; i< n ;i++){
        if(sum + r[i]>= 0){
            sum += r[i];
        }
        else{
            sum = 0;
        }
    }
    for(long long i = 0; i< m ;i++){
        if(rw + c[i]>= 0){
            rw += c[i];
        }
        else{
            rw = 0;
        }
    }
    cout << max(rw  , sum) << sad;
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