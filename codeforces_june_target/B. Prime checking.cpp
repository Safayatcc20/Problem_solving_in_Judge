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
    long long n ;
    cin >> n;
    long long flag = 0;
    for(long long i = 2 ; i * i <= n ; i++){
        if(n % i == 0){
            flag = 1;
            break;
        }
    }
    if(flag || n == 1){
        cout << "NO" << sad;
    }
    else{
        ha;
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