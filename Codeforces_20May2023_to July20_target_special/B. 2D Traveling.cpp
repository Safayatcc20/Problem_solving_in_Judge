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
    long long n , k , a , b;
    cin >> n >> k >> a  >> b;
    vector<pair<long long , long long>>v(n);
    for(auto &x:v){
        cin >> x.first >> x.second;
    }
    //cout << v[a-1].first << " "<< v[b-1].first << sad;
    long long dif1 = 1e18,dif = abs(v[a-1].first - v[b-1].first)+ (abs(v[a-1].second -v[b-1].second));
    long long ans = 0;
    //cout << dif << sad;
    //dif = abs(v[i].first - v[b-1].first)+ (abs(v[a-1].second -v[0].second));
    for(int i = 0 ; i < k ;i++){
        //cout << abs(v[i].first - v[b-1].first)+ (abs(v[i].second -v[b-1].second)) << " ";
        dif1 = min(dif1 , abs(v[a-1].first - v[i].first)+ (abs(v[a-1].second -v[i].second)));
    }
    ans = dif1;
    //cout << ans << " ";
    dif1=  abs(v[0].first - v[b-1].first)+ (abs(v[0].second -v[b-1].second));
    for(int i = 0 ; i < k ;i++){
        //cout << abs(v[i].first - v[b-1].first)+ (abs(v[i].second -v[b-1].second)) << " ";
        dif1 = min(dif1 , abs(v[i].first - v[b-1].first)+ (abs(v[i].second -v[b-1].second)));
    }
    cout << min(dif , dif1 + ans) << sad;
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