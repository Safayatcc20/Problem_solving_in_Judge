//unsolved///////////
#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n , q;
    cin >> n >> q;
    long long a[n];
    long long sum = 0;
    for(long long i = 1 ; i <= n; i++ ){
        cin >> a[i];
        sum += a[i];
    }
    while(q--){
        long long t;
        cin >> t;
        long long ind , x ;
        if(t == 1){
            cin >> ind >> x;
            long long r = a[ind];
            a[ind] = x;
            sum = sum + a[ind] - r;
        }
        else{
            cin >> x;
            sum = n * x;
        }
        cout << sum << "\n";
        sum = 0;
    }
}
int main(){
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}