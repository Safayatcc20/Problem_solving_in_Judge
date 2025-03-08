/*
   **** Author: Md. Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
#define end '\n' 
void solve()
{
    long long n ;
    cin >> n;
    string s;
    cin >> s;
    long long sum = 0, cnt = 0, ct = 0;
    vector<long long>v(n);
    for(auto &x:v){
        cin >> x;
        sum += x;
    } 
    for(long long i = 0 ; i <  n ; i++){
        if(s[i] == '0'){
            cnt++;
        }
        else{
            ct++;
        }
    }
    if(cnt == n || ct == n){
        cout << n ;
        return ;
    }
    sum = sum / n;
    long long ans = 0;
    for(long long i = 0; i < n ;i++){
        if(sum <= v[i] && s[i] == '1'){
            ans++;
        }
        else if(sum > v[i] && s[i] == '0'){
            ans++;
        }
    }
    cout << ans << end;
}
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    /* long long t;
    cin >> t;
    while(t--){ */
        solve();
    //}
}