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
    cin >> n ;
    string s;
    cin >> s;
    string ans = "";
    for(long long i = n-1; i >= 0; i--){
        if(s[i] == '0'){
            long long no = 10*(s[i-2] - 48 )+ s[i-1] - 48;
            //cout << no << sad;
            ans +=  no + 'a' - 1;
            i -= 2;
        }
        else{
            long long no = s[i] - 48;
            //cout << no << sad;
            ans +=  no + 'a' - 1;
        }
    }
        reverse(all(ans));
    cout << ans << sad;
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