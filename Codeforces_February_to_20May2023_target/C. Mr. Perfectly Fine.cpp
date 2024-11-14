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
bool comp(pair<long long , string > &a , pair<long long  , string >&b){
    return (a.first < b.first || a.first == b.first and ((a.second[0] == '1' and a.second[1] == '1') || a.second[0] == '1' || a.second[1] == '1'));
}
void solve(){
    long long n ;
    cin >> n;
    vector<pair<long long , string >>v(n);
    for(long long i = 0 ; i < n ; i++){
        cin >> v[i].first >> v[i].second;
    }
    long long fone = INT_MAX , sone = INT_MAX , two = INT_MAX, ans = INT_MAX;
    for(long long i = 0 ; i < n; i++){
        if(v[i].second == "11") two = min(two , v[i].first);
        if(v[i].second == "10") fone = min(fone , v[i].first);
        if(v[i].second == "01") sone = min(sone , v[i].first);
    }
    if(two != INT_MAX){
        cout << min(two , fone + sone) << sad;
    }
    else if(fone != INT_MAX and sone != INT_MAX){
        cout << min( two , fone + sone) << sad;
    }
    else{
        cout << -1 << sad;
    }
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