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
// remember MOD depends on statement;
const long long MOD = 1000000000; // 10^9

long long power(long long x, long long n) {
    if (n == 0) {
        return 1;
    }
    long long y = power(x, n / 2);
    if (n % 2 == 0) {
        return (y * y) ;
    } else {
        return (((y * y)) * x);
    }
}
void solve(){
    long long n;
    cin >> n;
    if( n < 7 ) {
        na;
        return;
    }
    for(long long i = 2; i < n/2; i++){
        long long sum = 0;
        long long cnt = 1;
        long long take = n;
        while(take > 1){
            take /= i;
            cnt++;
        }
        sum += (power(i , cnt) - 1)/ ( i - 1);
        //cout << sum << sad<< sad;
        if(sum == n) {
            ha;
            return;
        }
    }
    na;
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