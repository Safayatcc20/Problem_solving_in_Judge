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
    long long hc , dc , hm , dm;
    cin >> hc >> dc >> hm >> dm;
    long long k , w , a;
    cin >> k >> w >> a;
    //cout << ceil(3 / (2*1.0)) << sad;
    if(ceil(hc / (dm*1.0)) >= ceil(hm/(dc*1.0))){
        ha;
        return;
    }
    dc += (w * k);
    if(ceil(hc / (dm*1.0)) >= ceil(hm/(dc*1.0))){
        ha;
        return;
    }
    dc -= (w * k);
    hc += (a * k);
    if(ceil(hc / (dm*1.0)) >= ceil(hm/(dc*1.0))){
        ha;
        return;
    }
    hc -= (a * k);
    for(long long i = 1 ; i <= k ; i++){
        if(ceil((hc + ((i) * a))/ (dm*1.0)) >= ceil((hm*1.0) / (dc + ((k- i) * w)))){
            //cout << i << " ";
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