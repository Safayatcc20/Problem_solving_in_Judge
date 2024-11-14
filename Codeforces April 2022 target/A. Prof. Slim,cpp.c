#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long n;
    cin >> n;
    long long a[n];
    long long cnt = 0, mx = INT_MAX;
    for(long long i = 0; i < n; i++){
        cin >> a[i];
        if(mx < a[i]){
            mx = a[i];
            cnt++;
        }
    }
    if(cnt == n){
        cout << "YES" << "\n";
    }

}
int main ()
{
    long long t;
    cin >> t;
    while(t--){
        solve();
    }

}
