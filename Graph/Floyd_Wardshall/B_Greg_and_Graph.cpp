/*
 **** Bismillahir Rahmanir Rahim ****
 */
 
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define int long long
long long t = 1;
constexpr bool multiple_test_cases = 1;
long long gcd(long long x, long long y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
long long lcm(long long x, long long y)
{
    return ((x * y) / gcd(x, y));
}
const long long N = 10000;
long long prime[N];
long long fact(long long n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}
long long findXor(long long n){//reming: function calling findXor(sending value - 1);
    long long rest = n % 4;
    if(rest == 0) return n;
    if(rest == 1) return 1;
    if(rest == 2) return n+1;
    if(rest == 3) return 0;
}
void solve(){
    int n ;
    cin >> n;
    int v[n][n];
    int dist[n+1][n+1];
    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= n ; j++){
            cin >> dist[i][j];
        }
    }
    vector<int>del(n) , ans;
    for(auto &x:del) cin >> x;
    
    reverse(all(del));
    for(int k = 0 ; k < n; k++){
        int val = del[k];
        for(int i = 1;i <= n; i++){
            for(int j =  1; j<= n ;j++){
                dist[i][j] = min(dist[i][j] , dist[i][val] + dist[val][j]);
            }
        }
        int sum = 0 ;
        for(int i = 0 ; i <= k ;i++){
            for(int j = 0 ; j <=  k ; j++){
                sum += dist[del[i]][del[j]];
            }
        }
        ans.push_back(sum);
    }
    reverse(all(ans));
    for(auto &x:ans) cout << x << " ";
    cout << sad;

}
int32_t main()
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