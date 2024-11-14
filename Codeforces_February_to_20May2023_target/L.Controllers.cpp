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
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long ans = 0, p = 0 , minus = 0;
    for(long long i = 0 ; i < n; i++){
        if(s[i] == '+') p++;
        else{
            minus++;
        }
    }
    long long q;
    cin >> q;
    while(q--){
        long long x, y;
        cin >> x >> y;
        if(p == minus){
            ha;
            continue;
        }
        else{
            if( x== y){
                na;
                continue;
            }
            if(p < minus){
                long long a = min(x, y) , b = max(x , y);
                if(a * minus == b * p){
                    ha;
                    continue;
                }
                else if(minus - p == (x * minus-p *y)){
                    ha;
                    continue;
                }
                else if((a * min(minus,p)-b*min(minus,p)) / a == (a * min(minus,p)-b*min(minus,p)) || (a * min(minus,p)-b*min(minus,p)) / b == (a * min(minus,p)-b*min(minus,p)) ){
                    ha;
                    continue;
                }
                else{
                    na;
                }
            }
            else{
                long long b = min(x, y) , a = max(x , y);
                if(a * minus == b * p){
                    ha;
                    continue;
                }
                else if(minus - p == (x * minus-p *y)){
                    ha;
                    continue;
                }
                else if((a * min(minus,p)-b*min(minus,p)) / a == (a * min(minus,p)-b*min(minus,p)) and (a * min(minus,p)-b*min(minus,p)) / b == (a * min(minus,p)-b*min(minus,p)) ){
                    ha;
                    continue;
                }
                else{
                    na;
                }
            }
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
    //cin >> t;
    while (t--)
    {
        solve();
    }
}