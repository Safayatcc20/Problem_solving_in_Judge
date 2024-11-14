/*
 **** Bismillahir Rahmanir Rahim ****
 */
 
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.rbegin(), b.rend()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define minusone cout << "-1" << '\n'
long long t = 1;
constexpr bool multiple_test_cases = 1;
void solve(){
    long long a , b , n;
    cin >>  a >> b >> n;
    vector<long long>v(n);
    for(auto &x:v) cin >> x;
    sort(all(v));
    if(a == 1) {
        cout << 1 << sad;
        return;
    }
    long long ans = b-1, c = 1;
    for(int i = 0 ; i < n ; i++){
        c = min(c + v[i] , a);
        ans += (c-1);
        if(c-1 ==0 ){
            break;
        }
        c = 1;
    }
    cout << ans+ 1  << sad;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}