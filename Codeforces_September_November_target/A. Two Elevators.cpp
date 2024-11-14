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
    long long a , b , c;
    cin >> a >> b >> c;
    if(abs(b-c) + abs(c-1) < (a-1)){
        cout << 2 << sad;
    }
    else if(abs(b-c) + abs(c-1) > (a-1)){
        cout << 1 << sad;
    }
    else{
        cout << 3 << sad;
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