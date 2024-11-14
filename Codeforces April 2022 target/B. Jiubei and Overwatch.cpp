#include<bits/stdc++.h>
using namespace std;
void solve ()
{
    long long n , k , x , y;
    cin >> n >> k >> x >> y;
    long long a[n], mx = 0;
    for(long long  i = 0 ; i < n; i++){
        cin >> a[i];
        mx = max(a[i], mx);
    }
    if(mx <= k * x){
        if( mx % x == 0){
            cout << mx / x << "\n";
        }
        else{
            cout << mx / x + 1 << "\n";
        }
    }
    else{
        if( (mx - k * x) % y == 0){
            cout << (mx - k * x) / y + k << "\n";
        }
        else{
            cout << (mx - k * x) / y + 1 + k << "\n";
        }
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
