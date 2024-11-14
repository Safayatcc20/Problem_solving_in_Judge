#include<bits/stdc++.h>
using namespace std;
#define sad '\n'
#define no "NO"
#define yes "YES"
#define all(b) b.rbegin(), b.rend()
void solve(){
    long long n;
    cin >> n;
    vector<long long>v(n) , ans(n);
    for(auto &x:v) cin >> x;
    vector<pair<long long,  long long>>vv;
    for(long long i = 0; i <n; i++){
        vv.push_back({v[i], i});
    }
    sort(all(vv));
    long long k = 1;
    for(int i = 0 ; i < n ; i++){
        ans[vv[i].second] = k;
        k++;
    }
    for(auto &x:ans) cout << x << " " ;
    cout << sad;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long t = 1;
    cin >> t;
    long long i =1;
    while(t--) {
        //cout << "Case "<<i<<": ";
        i++;
        solve();
    }
}