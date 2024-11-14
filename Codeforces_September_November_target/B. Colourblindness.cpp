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
    long long n;
    cin >> n;
    long long t = 2;
    string a , b;
    cin >> a >> b;
    long long flag = 1;
    for(long long i = 0; i < n ; i++){
        if(a[i] == b[i]){
            continue;
        }
        else if(a[i] == 'G' && b[i] == 'B'){
            continue;
        }
        else if(a[i] == 'B' && b[i] == 'G'){
            continue;
        }
        else{
            flag = 0;
            break;
        }
    }
    if(flag ){
        ha;
    }
    else{
        na;
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