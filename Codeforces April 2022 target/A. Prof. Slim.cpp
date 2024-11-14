#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long n;
    cin >> n;
    long long a[n], r = n;
    long long cnt = 0, mx = INT_MIN;
    for(long long i = 0; i < n; i++){
        cin >> a[i];
        if(mx < a[i]){
            mx = a[i];
            cnt++;
        }
    }
    if(cnt == r){
        cout << "YES" << "\n";
    }
    else{
        long long neg = 0;
        for(long long i = 0 ; i < n ; i++){
            if(a[i] < 0){
                neg++;
            }
            a[i] = abs(a[i]);
        }
        for(long long i = 0 ; i < neg ; i++){
            a[i] = - a[i];
        }
        for(long long i = 1; i < n; i++){
           // cout << a[i - 1] << " ";
            if(a[i] < a[i-1] ){
                cout << "NO" << "\n";
                return ;
            }
        }
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

