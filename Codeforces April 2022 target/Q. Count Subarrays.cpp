//unsolved;
#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n;
    cin >> n;
    long long a[n];
    for(long long i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    long long cnt = 0;
    if(n == 1){
        cout << 1 << "\n";
    }
    else{
        for(long long i = 0; i < n; i++){
            for(long long j = i ; j < n; j++){
                for(long long k = i ; k < j; k++){
                    if(a[k] <= a[k+1] && a[j - 2] <= a[j - 1]){
                        cnt++;
                    }
                }
            }
        }
        cout << cnt << "\n";
    }
}
int main()
{
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}
