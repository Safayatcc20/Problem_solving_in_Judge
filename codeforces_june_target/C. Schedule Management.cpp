/*
   **** Author: Md. Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
void solve() {
    long long n,m;
    cin >> n >> m;
    vector < long long> v(m);
    map<long long, long long>mp;
    set<long long>s;
    for(auto &x:v) {
        cin >> x;
        mp[x]++;
        s.insert(x);
    }
    long long sum = 0, cnt= 0;
    v.assign(s.begin(), s.end());
    for(long long i = 0; i < v.size(); i++) {
        if(mp[v[i]] == 1) {
            cnt++;
        }
    }
    if(cnt == n) {
        cout << 1 << '\n';
        return ;
    }
    for(long long i = 0; i < v.size(); i++) {
        if(mp[v[i]] > 1) {
            sum += mp[v[i]] -1;
        }
        else {
            sum += mp[v[i]];
        }
    }
    cout << sum << '\n';
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