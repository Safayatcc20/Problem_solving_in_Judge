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
    long long n ;
    cin >> n;
    string s ;
    int mn = 9;
    while(n > 0){
        while(n < mn){
            mn = n;
        }
        s += ('0' + mn);
        n -= mn;
        //cout << s << sad;
        mn--;
    }
    reverse(s.begin() , s.end());
    cout<< s << sad;
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