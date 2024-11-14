/*
   **** Bismillahir Rahmanir Rahim ****
   **** Author: Md. Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
#define all(b) b.begin() , b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
void solve()
{
    long long n;
    cin >> n;
    if(n == 1){
        cout << 2 << sad;
        return ;
    }
    if( n < 4){
        cout << 1 << sad;
        return;
    }
    if(n % 3){
        cout << n / 3 + 1 << sad;
    }
    else{
        cout << n / 3 << sad;
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