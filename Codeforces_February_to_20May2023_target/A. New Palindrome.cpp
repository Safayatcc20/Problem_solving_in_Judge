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
    long long n = s.size();
    map<char , long long>mp;
    for(long long i = 0 ; i <n ; i++){
        ss.insert(s[i]);
        mp[s[i]]++;
    }
    if(ss.size() == 1){
        na;
        return;
    }
    long long odd = 0 , chk = 0 , even = 0;
    if(s.size()  & 1){
        if(ss.size() == 2){

            for(auto &x:mp){
                if(x.second & 1){
                    odd++;
                    chk = x.second;
                }
                else{
                    even++;
                }
            }
            if(odd == 1 and chk > 1){
                ha;
            }
            else{
                na;
            }
        }
        else{
            for(auto &x:mp){
                if(x.second & 1){
                    odd++;
                }
            }
            if(odd == 1){
                ha;
            }
            else{
                na;
            }
        }
    }
    else{
        for(auto &x:mp){
            if(x.second & 1){
                odd++;
            }
        }
        if(odd == 0){
            ha;
        }
        else{
            na;
        }
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