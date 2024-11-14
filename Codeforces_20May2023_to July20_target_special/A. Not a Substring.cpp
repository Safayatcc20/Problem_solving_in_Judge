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
    string s;
    cin >> s;
    int n = s.size();
    string t , c;
    for(int i = 1; i <= n; i++){
        t += '(';
    }
    for(int i = 1; i <= n; i++){
        t += ')';
    }
    for(int i = 1; i <= n*2; i++){
        if(i & 1) c += '(';
        else  c += ')';
    }
    bool ok  = false;
    //cout << t << " " << c << sad;
    for(int  i = 0 ; i < n * 2; i++){
        if(s[0] == t[i]){
            int k = i;
            bool f = true;
            for(int j = 0 ; j < n; j++){
                if(s[j] != t[k]){
                    f = false;
                    break;
                }
                else{
                    k++;
                }
            }
            if(f){
                ok = true;
                break;
            }
        }
    }
    if(ok){
        for(int  i = 0 ; i < n * 2; i++){
            if(s[0] == c[i]){
                int k = i;
                bool f = true;
                for(int j = 0 ; j < n; j++){
                    if(s[j] != c[k]){
                        f = false;
                        break;
                    }
                    else{
                        k++;
                    }
                }
                //cout << f << sad;
                if(f){
                    na;
                    return;
                }
            }
        }
        ha;
        cout << c << sad;
    }
    else{
        ha;
        cout << t << sad;
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