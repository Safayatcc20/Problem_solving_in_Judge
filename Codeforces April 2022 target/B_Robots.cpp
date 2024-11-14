#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n , m;
    cin >> n >> m;
    char s[n][m];
    long long val = INT_MAX, ans = - 1;
    for(long long i = 0 ; i < n; i++){
        for(long long j = 0 ; j < m;  j++){
            cin >> s[i][j];
            if(s[i][j] == 'R' && ans == -1){
                ans = j;
            }
            if(s[i][j] == 'R'){
                val = min(val , j);
            }
        }
    }
    if(ans <= val){
        cout << "YES" << "\n";
    }
    else{
        cout << "NO" << "\n";
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
