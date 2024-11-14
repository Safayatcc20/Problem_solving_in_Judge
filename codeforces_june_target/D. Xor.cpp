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
long long zor(long long a  , long long b , long long q){
    if(q == 1) return a;
    if(q == 2) return b;
    return zor(a , b ,(q-1)^(q-2));
}
void solve()
{
    long long a , b , q;
    cin >> a >> b >> q;
    cout << zor(a , b , q) << sad;
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