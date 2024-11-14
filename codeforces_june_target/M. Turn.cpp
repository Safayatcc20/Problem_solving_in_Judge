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
    long long n;
    cin >> n;
    if(n == 0){
        cout << 0 << sad;
        return;
    }
    if(n > 0){
        if(n <= 90){
            cout << 1 << sad;
        }
        else{
            cout << n / 90 << sad;
        }
    }
    else{
        n = 360 + n;
        if(n <= 90){
            cout << 1 << sad;
        }
        else{
            cout << n / 90 << sad;
        }
    }
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