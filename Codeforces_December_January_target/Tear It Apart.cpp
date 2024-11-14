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
    string s;
    cin >> s;
    set<char>ss;
    map<char , long long>c ;
    for(auto &x:s){
        c[x]++;
        ss.insert(x);
    }
    long long ans = 0 , n = s.size();
    for(auto x:ss){
        map<long long , long long> mp;
        char ch = x;
        long long j , ind = -1 ,all= 0;
        
        j = 0;
        if(s[0] == ch) j++;
        for(; j < n ;){
            if(s[j] != ch and mp[j]!= 1){
                j+=2;
                all++;
                mp[j] = 1;
            }
            else if(mp[j]){
                j++;
            }
            if(all == n - c[x]){
                break;
            }
            if(j >= n){
                j = ind+1;
            }
        }
        ans++;
        
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