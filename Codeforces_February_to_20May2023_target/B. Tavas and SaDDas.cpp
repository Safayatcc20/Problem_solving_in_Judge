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
// remember MOD depends on statement;
const long long MOD = 1000000000; // 10^9

long long power(long long x, long long n) {
    if (n == 0) {
        return 1;
    }
    long long y = power(x, n / 2);
    if (n & 1) {
        return (((y * y) % MOD) * x) % MOD;
    } 
    else {
        return (y * y) % MOD;
    }
}
void solve(){
    long long n;
    cin >> n;
    if(n == 4){
        cout << 1 << sad;
        return;
    }
    if(n == 7){
        cout << 2 << sad;
        return;
    }
    long long cnt = 0, seven = 0 , take = n , ind = 2;
    while(take > 0){
        cnt++;
        if(take % 10 == 7){
            seven++;
        }
        take /= 10;
    }
    if(seven == cnt){
        cout << 2 * (power(2 , cnt ) - 1) << sad;
        return;
    }
    ind = 2 * (power(2 , cnt - 1) - 1);
    long long four = cnt - seven;
    if(seven == 0){
        cout << ind + 1 << sad;
        return;
    }
    take = n;
    ind = 0 , cnt = 0;
    while(take > 0){
        if(take % 10 == 7){
            ind += (1 << cnt);
            //cout << ind  << cnt <<  sad;
        }
        take /= 10;
        cnt++;
    }
    //cout << "Cnt : " << cnt << sad;
    for(long long i = 1 ; i < cnt  ; i++){
        //cout << (1 << i) << " ";
        ind += (1 << i);
        //cout << ind << sad;
    }
    cout << ind + 1 << sad;
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