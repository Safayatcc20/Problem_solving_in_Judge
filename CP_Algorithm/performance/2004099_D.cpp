/*
 **** Bismillahir Rahmanir Rahim ****
 */
 
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define minusone cout << "-1" << '\n'
long long t = 1;
int dp[100][100000];
int n ;
int ddp[1000];
bool check(vector<int>&v , int i , int val){
    if(i < 0 or val <= 0) return 0;
    if(ddp[i]!=-1){
        return ddp[i] == val;
    }
    if(v[i] > val){
        ddp[i] = ddp[i] + check(v, i-1 , val);
    }
    else {
        ddp[i] = (ddp[i] + v[i]+check(v , i-1 , val - v[i]));
        ddp[i] = ddp[i] + check(v, i-1 , val);
    }
    return ddp[i] == val;
}
void solve(){
    cin >> n;
    vector<int>v(n);
    map<int , int>mp;
    for(auto  &x:v) {
        cin >> x;
        mp[x] = 1;
    }
    memset(dp , -1 , sizeof(dp));
    int val;
    cin >> val;
    if(mp[val]){
        cout << 1 << endl;
    }
    else{
        cout << check(v , n-1 , val) << sad;
    }

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}