/*
   **** Bismillahir Rahmanir Rahim ****
*/

#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
#define all(b) b.begin() , b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
long long t = 1;
void solve()
{
    long long n , m;
    cin >> n >> m;
    char v[n+5][m+5];
    memset(v , - 1 , sizeof(v));
    for(long long i = 0; i < n ; i++){
        for(long long j = 0; j < m;j++){
            cin >> v[i][j] ;
        }
    }
    long long cnt = 0 , zero = 0;
    for(long long i = 0; i < n ; i++){
        for(long long j = 0; j < m; j++){
            if(v[i][j] == '1'){
                cnt++;
            }
        }
    }
    for(long long i = 0; i < n ; i++){
        for(long long j = 0; j < m; j++){
            if(v[i][j] == '0'){
                zero++;
            }
        }
    }
    if(zero == 0){
        cout << cnt - 2 << sad;
        return;
    }
    if(cnt == 0){
        cout << 0 << sad;
        return;
    }
    bool flag = false;
    for(long long i = 0; i < n ; i++){
        for(long long j = 0; j < m; j++){
            if(v[i][j] == '0' && (v[i][j+1] == '0' || v[i][j-1] == '0'||v[i+1][j+1] == '0' || v[i+1][j-1] == '0'||v[i+1][j] == '0' || v[i-1][j-1] == '0'||v[i-1][j+1] == '0' || v[i-1][j] == '0')){
                flag = true;
                break;
            }
        }
    }
    if(flag){
        cout << cnt << sad;
    }
    else{
        cout << cnt - 1 << sad;
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