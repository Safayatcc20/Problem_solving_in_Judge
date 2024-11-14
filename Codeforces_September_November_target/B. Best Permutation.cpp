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
    if(n % 2){
        cout << 1 << " ";
        for(long long i = n -2; i > 1 ; i--){
            cout << i << " ";
        }
        cout << n - 1 << " " << n  << sad;
        return;
    }
    for(long long i = n-2; i > 0 ; i--){
        cout << i << " ";
    }
    cout << n - 1 << " " << n  << sad;
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