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
    long long  n;
    cin >> n ;
    long long cnt = 0;
    for(long long i = n / 3 ; i > 0; i--){
        long long a = i;
        long long j = n /
        for(; j >= i; j--){
            long long b = j;
            long long c = n - a - b;
            if(c >= b &&a + b >= c && b + c >= a && a + c >= b){
                cnt++;
                //cout << i << " " << j << " " << c << sad;
            }
        }
    }
    cout << cnt << sad;
}
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}