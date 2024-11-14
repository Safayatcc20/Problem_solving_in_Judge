#include<bits/stdc++.h>

using namespace std;
int main ()
{
    long long t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        long long a[n], cnt = 0, cnt2 = 0;
        for ( long long i = 1; i <= n ; i++){
            cin >> a[i];
            a[i] = a[i] + 1;
        }
        for(long long i = 1; i <= n; i++){
            if(a[i] % 2 == 0){
                cnt++;
            }
            else{
                cnt2++;
            }
        }
        if(cnt == n || cnt2 == n){
            cout << "YES" << "\n";
        }
        else{
            cnt = 0, cnt2 = 0;
            for(long long i = 1; i <= n; i++){
                if(i % 2 != 0){
                    a[i] += 1;
                }
                if(a[i] % 2 != 0){
                    cnt++;
                }
                else{
                    cnt2++;
                }
            }
            if(cnt == n || cnt2 == n){
                cout << "YES" << "\n";
            }
            else{
                cout << "NO" << "\n";
            }
        }
    }
}
