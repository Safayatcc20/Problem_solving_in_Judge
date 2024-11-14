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
long long gdcd(long long x , long long y){
    while(y > 0){
        long long temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}
void solve()
{
    long long x , y;
    cin >> x >> y;
    long long mul = x * y;
    //cout << gdcd(x , y) << sad;
    if( mul / gdcd(x , y) > y && abs(x - y) ){
        cout << -1 << " " << -1 << sad;
    }
    else{
        cout << x << " " << sad;
    }
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