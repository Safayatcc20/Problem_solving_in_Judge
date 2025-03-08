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
    vector<pair<int , int>>v(n);
    for(auto &x:v) cin >> x.first;
    for(auto &x:v) cin >> x.second;
    sort(all(v));
    long long ans = 0 ;
    for(long long i = 0; i < n ;i++){
        ans += (abs(v[i].first - v[n-1].first)) * v[i].second;
    }
    long long l =  v[0].first  , r = v[n-1].first; 
    while(l <= r){
        long long mid = l + ( r- l) / 2;
        long long sum1 = 0 , sum2 =  0 ;
        for(long long i = 0 ;i < n ;i++){
            sum1 += (abs(v[i].first - mid)) * v[i].second;
        }
        for(long long i = 0 ;i < n ;i++){
            sum2 += (abs(v[i].first - mid-1)) * v[i].second;
        }
        ans = min({ans , sum1 , sum2});
        if(sum1 < sum2){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout << ans << sad;
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