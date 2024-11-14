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
    long long a = 0, b = 0 ;
    long long c = 0, d = 0 ;
    while (n--)
    {
        long long x , y;
        cin >> x >> y;
        a = max(a , x) , b = min(b , x);
        c = max(c , y) , d = min(d , y);
        /* code */
    }
    cout << 2 * (a - b  + c - d) << sad;
    
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