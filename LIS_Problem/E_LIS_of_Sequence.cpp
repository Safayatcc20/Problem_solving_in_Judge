#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;
int mx  = -1 , mx_lis = 0 ;

string LIS(vector<int>& a) {
    int n = a.size();
    const int INF = 1e18;
    vector<int> d1(n , INF), d2(n , INF) , f1(n , 0) ,f2(n , 0);
    d1[0] = -INF;
    d2[0] = -INF;
    for (int i = 0; i < n; i++) {
        int l1 = lower_bound(d1.begin(), d1.end(), a[i]) - d1.begin();
        
        d1[l1] = a[i];
        mx = max(mx , a[i]);
        mx_lis = max(mx_lis, l1);
        f1[i] = l1;
    }
    for (int i = n-1; i >= 0 ;i--) {
        int l1 = lower_bound(d2.begin(), d2.end(), mx - a[i]) - d2.begin();
        
        d2[l1] = mx - a[i];
        f2[i] = l1;
    }
    //cout << mx_lis <<endl;
    vector<bool>vis(n ,false);
    vector<int>c(n+1 , 0);
    for(int i = 0 ; i < n ; i++){
        if(f1[i] + f2[i] - 1 == mx_lis){
            vis[i] = true;
            c[f1[i]]++;
        //cout << f1[i] << " & "<< f2[i] << " for idx = " << i << endl;
        }
    }
    string res;
    for (int i = 0 ; i < n ; i++) {
        //cout << c[f1[i]] << " ";
        if (vis[i] == false) res += '1';
        else if (c[f1[i]] == 1) res += '3';
        else res += '2';
    }
    return res;
}


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    
    cout << LIS(a) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
