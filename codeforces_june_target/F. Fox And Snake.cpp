#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n , m;
    cin >> n >> m;
    for(long long i = 1; i <= n ; i++){
        for(long long j = 1; j <= m; j++){
            if(i%2){
                cout << "#";
            }
            else{
                if(i % 4 == 0){
                    if(j == 1){
                        cout << "#";
                    }
                    else{
                        cout << ".";
                    }
                }
                else{
                    if(j == m){
                        cout << "#";
                    }
                    else{
                        cout << ".";
                    }
                }
            }
        }
        cout << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //long long t;
    //cin >> t;
    //while(t--){
        solve();
    //}
}

