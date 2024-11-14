#include<bits/stdc++.h>

using namespace std;
int main ()
{
    long long t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        long long a[n];
        for ( long long i = 0; i < n ; i++){
            cin >> a[i];
        }
        long long cnt = 0, rem = 0 ;
        sort(a, a+n);
        for(long long i = 0 ; i < n ; i++){
            if(a[i] == a[i+1]){
                cnt++;
                if(cnt == 2){
                    rem = a[i];
                    break;
                }
            }
            else{
                cnt = 0;
            }
        }
        if(rem ){
            cout << rem << "\n";
        }
        else{
            cout << -1 << "\n";
        }
    }
}
