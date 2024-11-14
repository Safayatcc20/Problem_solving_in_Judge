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
  return gcd(y , abs(x-y));
}
void solve()
{
    long long n;
    cin >> n;
    vector<long long>v;
    for(long long i = 0; i < n ; i++){
        long long x ;
        cin >> x;
        v.push_back(x);
    }
    long s = 0 , d = 0;
    for(long long i = 1; i <= n; i++){
        long long mx = max_element(all(v)) - v.begin();
        long long r = v[mx];
        v.erase(v.begin() + mx);
        if(i % 2){
            s += r;
        }
        else{
            d += r;
        }
    }
    cout << s << " " << d ;
}
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //long long t;
   // cin >> t;
    while(t--){
        solve();
    }
}