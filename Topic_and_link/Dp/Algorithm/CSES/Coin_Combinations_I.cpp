#include<bits/stdc++.h>
using namespace std;
#define sad '\n'
#define no "NO"
#define yes "YES"
#define int long long
const int mod =1000000007;
int coin1(int n,vector<int>&v,vector<int>& dp,int k){
    if(n == 0) return 1;
    if(dp[n] != -1) return dp[n];
    int ans = 0;
    for(int i = 0; i <k; i++){
        if(n - v[i] >= 0){
            ans = (ans+coin1(n - v[i], v,dp,k)) %mod;
        }
    }
    return dp[n] = ans;  
}
 
void solve(){
    int n,x;
    cin >>n >> x;
    vector<int>v(n);
    for(auto &x:v) cin >> x;
    vector<int>dp(x+1, -1);
    cout << coin1(x,v,dp,n) << sad;
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
