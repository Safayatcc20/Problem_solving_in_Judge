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
    long long n  , k , x , y;
    cin >> n >> k >> x >> y;
    map<long long , long long>mp;
    
    /* char v[n+1][n+1];
    for(long long i  = 1 ; i <= n ;i++){
        for(long long j = 1; j <= n; j++){
            v[i][j] = '.';
        }
    }
    for(long long l = 2; l <= n * 2; l++){
        if(abs(l - x - y) % k == 0){
        for(long long i  = 1 ; i <= n ;i++){
            for(long long j = 1; j <= n; j++){
                if(i+ j == l){
                    v[i][j] = 'X';
                }
            }
        }
        }
    }
    for(long long i  = 1 ; i <= n ;i++){
        for(long long j = 1; j <= n; j++){
            cout << v[i][j] ;
        }
        cout << sad;
    } */
    //jiangly
    for(long long i = 0; i < n ; i++){
        for(long long j = 0; j < n ; j++){
            cout << ".X"[((i - j ) % k + k) % k == ((x - y - 2) % k + k ) % k ];
        }
        cout << sad;
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