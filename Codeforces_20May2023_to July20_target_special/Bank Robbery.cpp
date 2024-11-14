/*
 **** Bismillahir Rahmanir Rahim ****
 */
 
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define minusone cout << "-1" << '\n'
long long t = 1;
void solve(){
    long long n;
    cin >> n;
    vector<long long>v(n);
    for(auto &x:v) cin >> x;
    if(n == 1){
        if(v[0] == -1) cout << 0 << sad;
        else cout << v[0] << sad;
    }
    if(n == 2){
        cout << max(v[0] , v[1]) << sad;
        return;
    }
    
    long long ans = 0;
    vector<long long>posible(n+1, 0);
    posible[1] = max(v[0] , posible[1]);
    for(int i = 2; i <= n ; i++){
        posible[i] = max(posible[i-1] , posible[i-2] + v[i-1]);
        ans = max(ans ,posible[i]);
    }
    cout << ans << sad;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}