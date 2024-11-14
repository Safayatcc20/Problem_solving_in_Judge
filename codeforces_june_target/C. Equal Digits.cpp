#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    long long me = 0 ,n = s.size() , val = 0;
    val = s[0] - '0';
    for(long long i = 0; i < n ; i++){
        me = me*10+s[i] - '0';
    }
    long long ans = 0;
    for(long long i = 0; i  < n; i++){
        ans = ans * 10 + val;
    }
    if(ans >= me){
        cout << ans << '\n';
    }
    else{
        ans = 0;
        val++;
        for(long long i = 0; i < n ; i++){
            ans = ans * 10 + val; 
        }
        cout << ans << '\n';
    }
}
