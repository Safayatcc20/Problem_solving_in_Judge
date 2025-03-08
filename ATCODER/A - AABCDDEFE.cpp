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
bool isBeautiful(long long x){
    string s= to_string(x);
    //cout << s << sad;
    return (s[0] != '0' and s[0] == s[1] and s[4] == s[5] and s[6] == s[8]);
}
void solve(){
    long long n ;
    cin >> n;
    long long cnt = 0 , t = 10;
    for(long long i = 1100000000;;){
        long long chk = i;
        long long go = 0;
        bool flg = true;
        while(go < 100){
            chk += go;
            string s = to_string(chk);
            if(isBeautiful(chk)){
                cnt++;
                if(cnt == n){
                cout << chk << sad;
                return;
                }
            }
            if(s[6] == '9' and s[7] == '9' and s[8] == '9') {
                i += 1100 * t;
                t *= 10;
                flg = false;
                break;
            }
            go = 10;
            if(s[6] == '0' and s[7] == '9' and s[8] == '0'){
                i++;
            }
        }
        if(flg)
        i++;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}