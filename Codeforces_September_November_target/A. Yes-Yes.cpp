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
    bool flag = true;
    long long y = 0, e = 0 , ss = 0;
    if(s.size() == 1){
        if(s[0] == 'Y' || s[0] == 'e' || s[0] == 's'){
            ha;
        }
        else{
            na;
        }
        return;
    }
    if(s.size() <= 2){
        if(s[0] == 's' and s[1] == 'Y'){
            ha;
        }
        else if(s[0] == 'e' and s[1] == 's'){
            ha;
        }
        else if(s[0] == 'Y' and s[1] == 'e'){
            ha;
        }
        else{
            na;
        }
        return;
    }
    for(long long i = 0 ; i < s.size()-2;i++){
        if(s[i] == 'Y' and s[i+1] == 'e' and s[i+2] == 's'){
            
            continue;
        }
        if(s[i] == 'e' and s[i+1] == 's' and s[i+2] == 'Y'){
            
            continue;
        }
        if(s[i] == 's' and s[i+1] == 'Y' and s[i+2] == 'e'){
            
            continue;
        }
        else{
            na;
            return;
        }
    }
    ha;
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