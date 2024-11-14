#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long a[n];
    long long cnt = 1, ans = 0;
    for(long long i = 1; i <= n; i++){
        if(s[i] == s[i-1]){
            cnt++;
        }
        else{
            if(cnt % 2 != 0){
                cnt = 0;
                ans++;
                continue;
            }
            else{
                cnt = 1;
            }
            cnt = 1;
        }
    }
    if(ans > 0){
        cout << ans << "\n";
    }
    else{
        cout << 0 << "\n";
    }
}
int main ()
{
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}
