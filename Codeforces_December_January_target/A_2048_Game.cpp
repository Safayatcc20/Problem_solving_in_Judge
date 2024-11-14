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
    /* long long n ;
    cin >> n;
    long long ans = 0 ;
    while ((n--))
    {
        long long x;
        cin >> x;
        if(x <= 2048)
        ans += x;
    }
    if(ans >= 2048){
        ha;
    }
    else{
        na;
    } */
    long long  n ;
    cin >> n;
    map<long long , long long>mp;
    vector<long long>v(n);
    for(auto &x:v){
        cin >> x;
        mp[x]++;
    }
    while(mp.size() > 0){
        if(mp.find(2048) != mp.end()){
            ha;
            return;
        }
        long long chk = -1;
        for(auto &x:mp){
            if(x.second > 1){
                chk = x.first;
                break;
            }
        }
        if(chk == -1){
            na;
            return;
        }
        mp[chk] -= 2;
        if(mp[chk] == 0) mp.erase(chk);
        mp[chk * 2]++;
    }
    na;
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