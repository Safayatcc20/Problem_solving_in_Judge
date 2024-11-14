#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n;
    cin >> n;
    vector<long long>v(n+1);
    map<long long , long long>cnt;
    for(long long i = 1; i <= n ;i++){
        cin >> v[i];
        cnt[v[i]]++;
    }
    for(auto it : cnt){
        if(it.second == 1){
            cout << -1 << "\n";
            return ;
        }
    }
    vector<long long>print(n+1);
    for(long long i = 1; i <= n ; i++){
        print[i] = i;
    }
    for(long long i = 1; i < n; i++){
        if(v[i] == v[i + 1]){
            swap(print[i] , print[i+1]);
        }
    }
    for(long long i = 1; i < n ; i++ ){
        cout << print[i] << " ";
    }
    cout << print[n] << "\n";
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
