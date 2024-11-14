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
    long long chk = 1;
    if(n == 1){
        ha;
        return;
    }
    while(chk * 2 <= n){
        chk *= 2;
        if(chk == n){
            ha;
            return ;
        }
    }
    na;
}
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    /* long long t;
    cin >> t; */
    while(t--){
        solve();
    }
}