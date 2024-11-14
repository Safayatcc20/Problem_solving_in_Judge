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
    long long n;
    cin >> n;
    string s;
    cin >> s;
    if(n & 1){
        minusone;
        return;
    }
    map<char , long long>mp , chk;
    for(auto &x:s){
        mp[x]++;
    }
    for(auto &x:mp){
        if(x.second > n / 2){
            minusone;
            return;
        }
    }
    bool f = false;
    for(long long i = 0 ; i < n /2 ; i++){
        if(s[i] == s[n-i-1]) {f = true ; break;}
    }
    if(f){
        long long ans = 0 ;
        for(long long i = 0 ; i < n / 2; i++){
            if(s[i] == s[n - i - 1]){
                mp[s[i]]--;
                ans++;
                chk[s[i]]++;
                for(auto &x:mp){
                    if(x.first != s[i]){
                        mp[x.first]--;
                        break;
                    }
                }
            }
            else{
                mp[s[i]]--;
                mp[s[n - i - 1]]--;
            }
        }
        for(auto &x:chk){
            if(x.second > (ans + 1) / 2){
                cout << x.second << sad;
                return;
            }
        }
        cout << (ans + 1) / 2 <<  sad;
    }
    else{
        cout << 0 << sad;
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