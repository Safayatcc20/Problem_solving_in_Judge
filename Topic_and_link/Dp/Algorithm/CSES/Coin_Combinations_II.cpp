#include<bits/stdc++.h>
using namespace std;
#define sad '\n'
#define no "NO"
#define yes "YES"
#define int long long
const int mod =1000000007;
 
void solve(){
    int n,x;
    cin >>n >> x;
    vector<int>v(n);
    for(auto &x:v) cin >> x;
    vector<int>dp(x+1, 0);
    dp[0] = 1;
    for(int i = 0; i < n ;i++){
        for(int j  = 1; j <= x; j++){
            if(j - v[i] >= 0){
                dp[j] = (dp[j] + dp[j-v[i]]) % mod;
            }
        }
    }
    cout << dp[x] << sad;
}
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long t = 1;
    //cin >> t;
    long long i =1;
    while(t--) {
        //cout << "Case "<<i<<": ";
        i++;
        solve();
    }
}
