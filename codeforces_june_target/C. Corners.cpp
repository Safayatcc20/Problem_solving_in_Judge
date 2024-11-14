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
    vector<string>v(n);
    for(long long i = 0; i < n ; i++){
        cin >> v[i];
    }
    long long cnt = 0 , zero = 0;
    for(long long i = 0; i < n ; i++){
        for(long long j = 0; j < m; j++){
            if(v[i][j] == '1'){
                cnt++;
            }
            if(v[i][j] == '0'){
                zero++;
            }
        }
    }
    if(zero == 0){
        cout << cnt - 2 << sad;
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