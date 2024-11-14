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
    long long n ;
    cin >> n;
    vector<pair<long long, long long>>v(n);
    for(int i= 0 ; i < n ; i++){
        cin >> v[i].first;
        v[i].second = i ;
    }
    long long k;
    cin >> k;
    sort(all(v));
    stack<pair<long long  ,long long>>s;
    map<long long , long long>mp;
    s.push({0 , LONG_LONG_MAX});
    long long prev = -1;
    for(int i = 0 ; i < n ; i++){
        if(i + 1 < n and v[i].first == v[i+1].first) continue;
        if(v[i].second < prev) continue;
        prev= v[i].second;
        mp[v[i].first]  = v[i].second;
        if(s.size()){
            auto chk= s.top();
            long long dif = v[i].first - chk.first;
            long long convert = (k / dif);
            convert= min(convert , chk.second);
            k -= (convert * dif);
            s.pop();
            s.push({chk.first , chk.second - convert});
            s.push({v[i].first , convert});
        }
    }
    vector<long long>ans(n);
    while(s.size()>1){
        auto chk = s.top();
        s.pop();
        //cout << chk.first << " "<< chk.second << sad;
        ans[mp[chk.first]] = chk.second;
    }
    reverse(all(ans));
    for(int i = 1; i < n ; i++){
        ans[i] += ans[i-1];
    }
    reverse(all(ans));
    for(auto &x:ans){
        cout << x << " ";
    }
    cout << sad;
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