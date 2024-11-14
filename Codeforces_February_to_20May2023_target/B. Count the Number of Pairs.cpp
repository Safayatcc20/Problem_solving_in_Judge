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
    long long n , k;
    cin >> n >> k;
    string s;
    cin >> s;
    long long ans = 0, mx = 0;
    map<char , long long>up , low;
    for(long long i = 0 ; i < n ; i++){
        if(s[i] >= 'A' and s[i] <= 'Z' ){
            up[s[i]]++;
            if(low[tolower(s[i])] > 0){
                low[tolower(s[i])]--;
                up[s[i]]--;
                ans++;
            }
        }
        else if(s[i] >= 'a' and s[i] <= 'z'){
            low[s[i]]++;
            if(up[toupper(s[i])] > 0){
                up[toupper(s[i])]--;
                low[s[i]]--;
                ans++;
            }
        }
    }
    for(auto &x:up){
        //cout << x.first << " " << x.second << sad;
    }
    if(low.size() <= up.size()){
        for(auto &x:up){
            if(k == 0) break;
            //cout << x.first << " " << x.second << sad;
            //cout << tolower(x.first) << " "  << low[tolower(x.first)] << sad;
            //cout << (x.second + low[tolower(x.first)])/2 << sad;
            if(k <= (x.second + low[tolower(x.first)])/2){
                ans += k;
                k = 0;
            }
            else{
                ans += (x.second + low[tolower(x.first)])/2;
                k -= (x.second + low[tolower(x.first)])/2;
            }
        }
    }
    else{
        for(auto &x:low){
            if(k == 0) break;
            //cout << x.first << " " << x.second << sad;
            //cout << tolower(x.first) << " "  << low[tolower(x.first)] << sad;
            //cout << (x.second + low[tolower(x.first)])/2 << sad;
            if(k <= (x.second + up[toupper(x.first)])/2){
                ans += k;
                k = 0;
            }
            else{
                ans += (x.second + up[toupper(x.first)])/2;
                k -= (x.second + up[toupper(x.first)])/2;
            }
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