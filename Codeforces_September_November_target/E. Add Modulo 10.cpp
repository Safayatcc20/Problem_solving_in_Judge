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
    long long n ;
    cin >> n;
    vector<long long>v(n);
    for(auto &x:v) {
        cin >> x;
    }
    long long zero = 0 , one = 0;
    for(long long i = 0; i < n ; i++){
        if(v[i] % 10 == 0 ){
            v[i] +=0;
        }
        else if(v[i] % 10 == 5 ){
            v[i] +=5;
        }
        else if(v[i] % 10 == 1 ){
            v[i] +=(1);
        }
        else if(v[i] % 10 == 2 ){
            v[i] = v[i];
        }
        else if(v[i] % 10 == 3 ){
            v[i] +=(3+6);
        }
        else if(v[i] % 10 == 4 ){
            v[i] +=(4+8+ 6);
        }
        else if(v[i] % 10 == 6 ){
            v[i] +=6;
        }
        else if(v[i] % 10 == 7 ){
            v[i] +=(7 + 4 + 8 + 6);
        }
        else if(v[i] % 10 == 8 ){
            v[i] +=(8 + 6);
        }
        else if(v[i] % 10 == 9){
            v[i] +=(9 + 8 + 6);
        }
    }
    bool flag = true;
    for(long long i = 0; i < n- 1; i++){
        if(abs(v[i] - v[i+1]) % 20 == 0 and (v[i] % 10 == 0 || v[i] % 10 == 5) and (v[i+1] % 10 == 0 || v[i+1] % 10 == 5) and v[i] != v[i+1]){
            flag = false;
            break;
        }
        if(abs(v[i]- v[i+1]) % 20){
            flag = false;
            break;
        }
    }
    if(flag){
        cout << "Yes" << sad;
    }
    else{
        cout << "No" << sad;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    // long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}