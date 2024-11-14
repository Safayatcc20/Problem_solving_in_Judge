#include<bits/stdc++.h>
#define all(b) b.begin() , b.end()
using namespace std;
void solve()
{
    long long n;
    cin >> n;
    vector<long long> v(n+1);
    vector<long long> p(n+1);
    for(long long i = 1; i <= n ;i++){
        cin >> v[i];
    }
    if(n == 1){
        cout << -1 << "\n";
    }
    else{
        for(long long i = 1; i <= n ;i++){
            p[i] = i;
        }
        for(long long i = 1; i <= n; i++){
            if(v[i] != p[i]){
                continue;
            }
            else if(i == n){
                swap(p[n] , p[n-1]);
            }
            else{
                swap(p[i] , p[i+1]);
            }
        }
        for(long long i = 1; i <= n ; i++){
            cout << p[i] << " ";
        }

        cout << "\n";
    }
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

