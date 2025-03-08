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
   
    long long n ,m ,t;
    while(cin >> n)
      if(n==0) break;
      else{
      m=n%10;
      m*=5;
      n/=10;
      n-=m;
      if(n < 0) n*=(-1);
      if(n%17==0) cout<<1<<endl;
      else cout<<0<<endl;
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