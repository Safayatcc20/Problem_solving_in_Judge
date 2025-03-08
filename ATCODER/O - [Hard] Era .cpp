#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n ;
    cin >> n;
    long long a[n] , mx = 0;
    a[0] = {0};
    for(long long i = 1; i <= n ; i++){
        cin >> a[i];
    }
    for(long long i = 1; i <= n ; i++){
        if(i < a[i] ){
            mx = max(mx ,a[i] - i);
        }
    }
    cout << (mx  )<< "\n";
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

