#include<bits/stdc++.h>
using  namespace std;
void solve(){
    long long n;
    cin >> n;
    vector<long long>s(n+1);
    vector<long long>f(n+1);
    vector<long long>r(n+n+2);
    for(long long i = 1; i <=n; i++){
        cin >> s[i];
    }
    for(long long i = 1; i <=n; i++){
        cin >> f[i];
    }
    for(long long i = 1; i < n; i++){
        long long x = f[i] - s[i];
        if(f[i-1] > s[i]){
            cout << f[i] - f[i-1] << " ";
        }
        else{
            cout << f[i] - s[i] << " ";
        }
    }
    if(f[n-1] > s[n]){
        cout << f[n] - f[n-1];
    }
    else{
        cout << f[n] - s[n];
    }
    cout << "\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}
