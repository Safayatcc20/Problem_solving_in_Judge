/*
   **** Author: Md. Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
#define end '\n' 
long long a[1000000]  = {-1}, b[1000000] = {-1};
void solve()
{
    long long n ;
    cin >> n;
    string s , t;
    cin >> s >> t;
    /* string ss = "", tt = "";
    for(long long i = 0; i < n ; i++){
        if(s[i] != 'b'){
            ss += s[i];
        }
    }
    for(long long i = 0; i < n ; i++){
        if(t[i] != 'b'){
            tt += t[i];
        }
    } */
    if(n == 1){
        if(s[0] == t[0]){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
        return;
    }
    long long b = 0 , bb = 0;
    for(long long i = 0 ; i < n; i++){
        if(s[i] == 'b'){
            b++;
        }
        if(t[i] == 'b'){
            bb++;
        }
    }
    if(b != bb++){
        cout << "NO" << "\n";
        return;
    }
    long long j = 0 ,  k = 0;
    for(long long i = 0 ; i < n; i++){
        if(s[i] == 'b'){
            continue;
        }
        while(t[j] == 'b'){
            j++;
        }
        if(s[i] != t[j] ||( s[i] == 'a' && i > j) || (s[i] == 'c' && i < j)){
            cout << "NO" << '\n';
           // break;
           return ;
        }
        j++;
    }
    cout << "YES"<< "\n";
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