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
    string a , b;
    bool f = false;
    for(int i = s.size()-1; i>= 0 ; i--){
        int chk = s[i] - '0';
        if(chk & 1){
            if(!f){
                a += chk/2 + '0';
                b+=chk/2 + 1 + '0';
                f = true;
            }
            else{
                f = false;
                b += chk/2 + '0';
                a +=chk/2 + 1 + '0';
            }
        }
        else{
            a += chk/2 + '0';
            b += chk/2 + '0';
        }
    }
    reverse(all(a));
    reverse(all(b));
    if(a[0] == '0' and a.size() > 1) {
        bool z = false;
        for(int i = 0 ; i < a.size()-1; i++){
            if(a[i]!= '0'){
                z = true;
                cout << a[i];
            }
            else if(z){
                cout << a[i];
            }
        }
        cout << a[a.size()-1] << " " ;
    }
    else cout << a << " ";
    if(b[0] == '0' and b.size() > 1) {
        bool z = false;
        for(int i = 0 ; i < b.size()-1; i++){
            if(b[i]!= '0'){
                z = true;
                cout << b[i];
            }
            else if(z){
                cout << b[i];
            }
        }
        cout << b[b.size()-1] << sad;
    }
    else cout  << b << sad;
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