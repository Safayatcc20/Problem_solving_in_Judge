/*
 **** Bismillahir Rahmanir Rahim ****
 */
 
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
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
    long long n;
    cin >> n;
    vector<long long> v(n) ,chker;
    for(auto &x:v) cin >> x;
    map<long long , long long>mp;
    long long ans = 0 , mx = 0 ;
    for(long long i = 0 ; i < n ; i++){
        mx  = max(mx , v[i]);
    }
    for(long long i = 0 ; i < n ; i++){
        if(v[i] != mx){
            long long t = 0 , sum = 0;
            for(long long j = i; j < n; j++){
                if(sum == mx){
                    break;
                }
                else if(sum > mx){
                    break;
                }
                sum += v[j];
                t++;
            }
            ans = max(t , ans);
        }
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
    cin >> t;
    while (t--)
    {
        solve();
    }
}