//unsolved//////////////
#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n;
    cin >> n;
    vector<long long>a(n+1) , b(n+1),dif(n+1);
    for(long long i = 1 ; i <= n; i++){
        cin >> a[i];
    }
    for(long long i = 1; i <= n ; i++){
        cin >> b[i];
    }
    long long equ = 0;
    for(long long i = 1; i <= n ; i++){
        if(a[i] == b[i]){
            equ++;
        }
    }
    if(equ == n){
        cout << "YES" << "\n";
    }
    else if(n == 1){
        if(a[1] >= b[1]){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }
    else{
        long long flag = 0;
        for(long long i = 1; i <= n; i++){
            if(a[i] < b[i]){
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            cout << "NO" << "\n";
        }
        else{
            long long mx = 0;
            for(long long i = 1; i <= n; i++){
                if(a[i] - b[i] == 0){
                    flag = 1;
                    break;
                }
                else{
                    long long ans = a[i] - b[i];
                    dif.push_back(ans);
                    mx = max(mx ,a[i] - b[i]);
                }
            }
            if(flag == 1){
                cout << "NO" ;
            }
            else {
                long long cnt = 0; flag = 0;
                sort(dif.begin() , dif.end());
                for(long long i = 0; i < dif.size(); i++){
                    if(mx - dif[i] == 0 || b[i+1] == 0){
                        cnt++;
                    }
                    else{
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1){
                    cout << "NO";
                }
                else{
                    cout << "YES";
                }
            }
            cout << "\n";
        }
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
