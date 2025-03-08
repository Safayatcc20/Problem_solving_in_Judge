#include<bits/stdc++.h>
using namespace std;
#define sad '\n'
#define no "NO"
#define yes "YES"
#define int long long
const int mod =1000000007;
int dice(int n, vector<int>& dp){
    if(n == 0) return 1;
    if(dp[n] != -1) return dp[n];
    int ans = 0;
    for(int i = 1; i <= 6; i++){
        if(n - i >= 0){
            ans = (ans+dice(n - i, dp)) %mod;
        }
    }
    return dp[n] = ans;  
}
 
void solve(){
    int n; cin >> n;
    vector<int>dp(n+1);
    for(int i =0; i <=n;i++) dp[i]=-1;
    cout << dice(n, dp)<< sad;
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