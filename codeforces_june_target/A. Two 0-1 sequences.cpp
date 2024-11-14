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
    long long n , m;
    cin >> n >> m;
    string a , b;
    cin >> a >> b;
    long long j  , i ;
    for(i = n - 1 , j = m - 1; i >= 0 && j >= 0 ; i--, j--){
        if(a[i] == b[j]){
            continue;
        }
        else{
            break;
        }
    }
    if(j < 0){
        ha;
        return;
    }
    if(j == 0){
        for(i ; i >= 0; i--){
            if(a[i] == b[j]){
                ha;
                return;
            }
        }
        na;
    }
    else{
        na;
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