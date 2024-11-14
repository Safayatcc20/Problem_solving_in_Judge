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
void solve()
{
    long long n , m , sx , sy  , d;
    cin >> n >> m >> sx >> sy >> d;
    if(sx + d < n && sy - d > 1 || sx - d > 1 && sy + d < m){
        cout << n + m - 2 <<sad;
    }
    else{
        cout << - 1 << sad;
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