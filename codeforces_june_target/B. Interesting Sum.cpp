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
void solve()
{
    long long n ;
    cin >> n ;
    vector<long long>v(n);
    for(auto &x:v) cin >> x;
    sort(all(v));
    long long a = v[0] ,b=  v[1] , c = v[n-2] , d = v[n-1];
    long long f = max({b , c ,d})-min({b , c ,d});
    long long ff = max({a , b})-min({a , b}) + max(c , d) - min(c , d);
    long long fff = max({a  , b , c})-min({a , b , c});
    long long ffff = max({c , b})-min({b , c}) + max(a , d) - min(a , d);
    cout << max({f , ff ,fff , ffff}) << sad;
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