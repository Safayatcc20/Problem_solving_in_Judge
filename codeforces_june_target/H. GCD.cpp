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
    long long x , y;
    cin >> x >> y;
    long long mul = x * y;
    long long res = gcd(x , y);
    cout << res << " " << mul / res << sad;

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