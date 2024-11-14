/*
   **** Author: Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n ;
    cin >> n;
    string s;
    cin >> s;
    if(s[0] == '9'){
        long long ch = 0;
        string ans = "";
        for(long long i = n-1; i >= 0; i--){
            long long check = s[i] - '0' + ch;
            if(check <= 1){
                ch = 0;
                ans += '0' + 1 - check;
            }
            else{
                ch = 1;
                ans += '0' + 11 - check;
            }
        }
        reverse(ans.begin() , ans.end());
        cout << ans ;
    }
    else{
        long long an = 0;
        for(long long i = 0; i < n ; i++){
            cout << 9 - (s[i] - '0');
        }
    }
    cout << '\n';
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