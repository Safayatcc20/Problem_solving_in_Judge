#include<bits/stdc++.h>
using namespace std;
#define sad '\n'
#define no "NO"
#define yes "YES"
void solve(){
    int n,x;
    cin >>n >> x;
    vector<int>v(n);
    for(auto &x:v) cin >> x;
    vector<int>dp(x+1, 1e9);
    dp[0]=0;
    for(int i = 1; i <=x ;i++){
        for(int j =0 ; j<n;j++){
            if(v[j]<=i){
                dp[i]= min(dp[i], dp[i-v[j]]+1);
            }
        }
    }
    cout <<(dp[x]!=1e9? dp[x]:-1)<< sad;
}
int main(){
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