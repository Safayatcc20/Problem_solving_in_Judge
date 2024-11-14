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
    long long n , x;
    cin >> n >> x;
    if(n < 3){
        cout << 1 << sad;
        return;
    }
    n -= 2;
    if(n % x){
        cout << n / x + 2 << sad;
    }
    else{
        cout << n / x+1 << sad;
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