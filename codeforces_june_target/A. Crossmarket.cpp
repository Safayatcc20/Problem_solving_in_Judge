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
    long long x , y;
    cin >> x >> y;
    if(x == 1 && y == 1){
        cout << 0 << sad;
        return;
    }
    if(x == 1 || y == 1){
        cout << x * y << sad;
        return;
    }
    cout << x + y + min(x  , y) - 2 << sad;
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