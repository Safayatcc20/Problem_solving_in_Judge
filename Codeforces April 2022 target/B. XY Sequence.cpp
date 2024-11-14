#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n ,  b , x , y;
    cin >> n >> b >> x >> y;
    long long sum = 0 , a[n];
    for(long long i = 0 ; i < n; i++){
        if(sum + x <= b){
            sum += x;
            a[i] = sum;
            cout << a[i] << " ";
        }
        else{
            sum += - y;
            a[i] = sum;
            cout << a[i] << " ";
        }
    }
    long long ans = 0;
    for(long long i = 0 ; i < n ; i++){
        ans += a[i];
    }
    cout << ans << "\n";
}
int main()
{
    long long t ;
    cin >> t;
    while(t--){
        solve();
    }
}
