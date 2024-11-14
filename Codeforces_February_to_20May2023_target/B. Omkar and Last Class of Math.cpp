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
    long long g= INT_MAX, a = 0 , b = 0 ;
    if(!(n&1)){
        if(g > (n/2 * (n-n/2)) / gcd(n/2 , n-n/2)){
            a = n/2 , b = n - n / 2;
            g = min(g , (n/2 * (n-n/2)) / gcd(n/2 , n-n/2));
        }
    }
    for(long long i = 3; i * i <= n; i+=2){
        if(n % i == 0){
            if(g > (n/i * (n-n/i)) / gcd(n/i , n-n/i)){
                a = n/i , b = n - n / i;
                g = min(g , (n/i * (n-n/i)) / gcd(n/i , n-n/i));
            }
            else if(g > (i * (n-i)) / gcd(i , n-i)){
                a = i , b = n - i;
                g = min(g , (i * (n-i)) / gcd(i , n-i));
            }
        }
    }
    if(a == 0 and b == 0){
        a = 1 , b = n - 1;
    }
    cout << a << " " << b << sad;
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